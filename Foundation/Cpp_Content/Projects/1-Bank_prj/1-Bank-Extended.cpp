#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::vector;
using std::fstream;
using std::ios;
using std::ws;
using std::setw;

enum enFuncs
{
  Display = 1,
  Insert = 2,
  Update = 3,
  Delete = 4,
  Find = 5,
  Transaction = 6,
  Exit = 7
};

enum enTrx
{
  Deposit = 1,
  Withdraw = 2,
  Balance = 3,
  MainMenu = 4
};

struct stClients
{
  string AccountNumber;
  uint16_t PinCode;
  string Fullname, PhoneNumber;
  double AccountBalance;
};

string prompt(const char *Msg);

char isUpper(char letter);

char isLower(char letter);

bool isLetter(char letter);

uint16_t wordCounter(string Text);

bool nameFormatChecker(string text);

bool accBalanceFormatChecker(string text);

stClients readClientData();

vector <stClients> vecFillerWithClients(stClients &Client, bool);

string convertToLine(stClients Client);

vector <string> saveRecs(vector <stClients> &vClients);

void saveRecordsToFile(vector <string> vRecs, const string filename);

vector <string> loadRecsToVec(const string filename);

vector <string> splitString(string line, string);

stClients restructRec(vector <string> vString);

vector <stClients> convertRecs(vector <string> &vRecs, stClients &Client);

void tableHeader(uint16_t &count);

string spacer(string text, uint16_t count);

void showClients(stClients Client);

void DisplayAllClient();

bool findClient(string AccNumber, stClients &Client, string);

void printClient(string AccNumber, stClients &Client);

void mainMenuDisplay();

void transactionsMenuDisplay();

void onExit();

bool getApproval(char getApproval);

vector <string> getAccNumbers(string AccNumber);

bool doesExist(string AccNumber);

void printTransactionMsg(uint16_t amount, string AccNumber, vector <stClients> vClients, const string Msg);

vector <string> depositInterface(string filename);

vector <string> withdrawInterface(string filename);

void tableCore(stClients Client);

void displayBalanceTable(string filename);

void transactionsHandler(uint16_t operationChoice);

void funcsSwitcher(uint16_t &operationChoice);

void onTrigger();

vector <string> deleteClient(string AccNumber, string);

int main(void)
{
  onTrigger();
  return (0);
}


string prompt(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin >> ws, Text);

  return (Text);
}

char isUpper(char letter)
{
  return (letter >= char(65) && letter <= char(90));
}

char isLower(char letter)
{
  return (letter >= char(97) && letter <= char(122));
}

bool isLetter(char letter)
{
  return (isUpper(letter) || isLower(letter));
}

uint16_t wordCounter(string Text)
{
  uint16_t i = 0, counter = 0;

  for (i = 0; i < Text.length(); ++i) {
    counter++;
  }

  return (counter);
}

bool nameFormatChecker(string text)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < text.length(); i++) {
    if (wordCounter(text) < 6) {
      cout<<"Name is way too short\n";
      return (false);
    }
    
    if (text[i - 1] == ' ' && isLetter(text[i])) {
      for (j = 0; j < text.length(); j++) {
	if (text[j] != ' ' && isLetter(text[j]) == false) {
	  cout<<"Wrong format no numbers are allowed in names\n";
	  return (false);
	}
      }
      return (true);
    }
  }

  
  cout<<"Wrong Format(ex: Jinwoo Sung)\n";
  
  return (false);
}

bool accBalanceFormatChecker(string text)
{
  uint16_t i = 0;
  
  for (i = 0; i < text.length(); ++i) {
    if (isLetter(text[i])) {
      cout<<"Account Balance should be a number\n";
      return (false);
    }
  }
  return (true);
}

stClients readClientData(bool skipAccNumber=false)
{
  stClients Client;
  string AccBalance;

  if (skipAccNumber == false) {
    do {
      Client.AccountNumber = prompt("Enter an account number: ");
      
    } while (doesExist(Client.AccountNumber) == true || !isUpper(Client.AccountNumber[0]) || wordCounter(Client.AccountNumber) < 4);
  }
  
  do {
    Client.PinCode = stoi(prompt("Enter a pin code: "));
  } while (wordCounter(to_string(Client.PinCode)) < 4);

  
  do {
    Client.Fullname = prompt("Enter your full name: ");
  } while (!nameFormatChecker(Client.Fullname));

  Client.PhoneNumber = prompt("Enter your phone number: ");

  do {
   AccBalance = prompt("Enter your initial deposit: ");
  } while (!accBalanceFormatChecker(AccBalance));

  Client.AccountBalance = stod(AccBalance);
  
  return (Client);
}

vector <stClients> vecFillerWithClients(stClients &Client, bool CheckCase=false)
{
  vector <stClients> vClients;
  char operation = 'N';

  do {
    Client = readClientData(false);
    
    vClients.push_back(Client);
    
    operation = char(prompt("\nDo you want to add more clients?")[0]);
    cout<<'\n';
    
    if (operation == 'y' || operation == 'Y') {
      CheckCase = true;
    } else {
      CheckCase = false;
    }
  } while (CheckCase);

  return (vClients);
}

string convertToLine(stClients Client)
{
  string line, delim = "#/\\#";
  
  line += Client.AccountNumber + delim;
  line += to_string(Client.PinCode) + delim;
  line += Client.Fullname + delim;
  line += Client.PhoneNumber + delim;
  line += to_string(Client.AccountBalance);
  
  return (line);
}

vector <string> saveRecs(vector <stClients> &vClients)
{
  vector <string> vRecs;

  for (const stClients &C : vClients) {
    vRecs.push_back(convertToLine(C));
  }

  return (vRecs);
}

void saveRecordsToFile(vector <string> vRecs, const string filename)
{
  fstream file;
  
  file.open(filename, ios::out | ios::app);

  if (file.is_open()) {
    for (const string &Rec : vRecs) {
      file<<Rec<<'\n';
    }
    file.close();
  }
}

vector <string> loadRecsToVec(const string filename)
{
  fstream file;
  vector <string> vRecs;
  
  file.open(filename, ios::in);

  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      vRecs.push_back(line);
    }
  }
  
  return (vRecs); 
}

vector <string> splitString(string line, string delim="#/\\#")
{
  vector <string> vString;
  short pos = line.find(delim);
  
  while (pos != string::npos) {
    vString.push_back(line.substr(0, pos));
    line.erase(0, pos + delim.length());
    pos = line.find(delim);
  }

  if (line != "") {
    vString.push_back(line);
    line.clear();
  }

  return (vString);
}

stClients restructRec(vector <string> vString)
{
  stClients Client;
  
  Client.AccountNumber = vString[0];
  Client.PinCode = stoi(vString[1]);
  Client.Fullname = vString[2];
  Client.PhoneNumber = vString[3];
  Client.AccountBalance = stod(vString[4]);
			       
  return (Client);
}

vector <stClients> convertRecs(vector <string> &vRecs, stClients &Client)
{

  vector <stClients> vClients;
  
  for (const string &rec : vRecs) {
    Client = restructRec(splitString(rec));
    vClients.push_back(Client);
  }

  return (vClients);
}

void tableHeader(uint16_t &count)
{
  cout<<"\n\t\t\t\tCurrent Registered Clients (Count ["<<count<<"])\n\n";
  cout<<"____________________________________________________"
      <<"___________________________________________________\n"
      <<" | Account Number"<<setw(13)
      <<" | Pin Code"<<setw(17)
      <<" | Fullname"<<setw(28)
      <<" | Phone Number"<<setw(22)
      <<" | Account Balance"<<'\n'
      <<"____________________________________________________"
      <<"____________________________________________________\n";
}

string spacer(string text, uint16_t count)
{
  uint16_t i = 0;
  string space = text;
  
  for (i = 0; i < (count - text.length()); i++) {
    space += ' ';
  }

  return (space);
}

void showClients(stClients Client)
{
  cout<<" | "<<Client.AccountNumber<<setw(15);
  cout<<" | "<<Client.PinCode<<setw(13);
  cout<<" | "<<spacer(Client.Fullname, 21);
  cout<<" | "<<spacer(Client.PhoneNumber, 16);
  cout<<" | "<<Client.AccountBalance<<endl;
}

void DisplayAllClient()
{
  uint16_t count;
  stClients Client;
  vector <stClients> vClients;
  vector <string> vRecs;
  string filename = "Clients/Data";
  vector <stClients>::iterator iter;

  vRecs = loadRecsToVec(filename);
  vClients = convertRecs(vRecs, Client);
  
  tableHeader((count = vClients.size()));
  
  for (iter = vClients.begin(); iter != vClients.end(); iter++) {
    showClients(*iter);
  }
  cout<<endl;
}

bool findClient(string AccNumber, stClients &Client, string filename="Clients/Data")
{
  vector <string> vRecs;
  vector <stClients> vClients;
  vRecs = loadRecsToVec(filename);
  vClients = convertRecs(vRecs, Client);
  
  for (const stClients &C : vClients) {
    if (AccNumber == C.AccountNumber) {
      Client = C;
      return (true);
    }
  }

  return (false);
}

void printClient(string AccNumber, stClients &Client)
{
  if (findClient(AccNumber, Client)) {
    cout<<"\n\nThe following are the client details: \n\n";
    cout<<"Account number: "<<Client.AccountNumber<<'\n';
    cout<<"Pin code: "<<Client.PinCode<<'\n';
    cout<<"Fullname: "<<Client.Fullname<<'\n';
    cout<<"Phone number: "<<Client.PhoneNumber<<'\n';
    cout<<"Account balance: "<<Client.AccountBalance<<'\n'<<endl;
  } else {
    cout<<"\nClient with this account number ("<<AccNumber<<") is not found!\n"<<endl;
  }
}

void mainMenuDisplay()
{
  cout<<"-----------------------------------------\n"
      <<setw(25)<<"Main Menu"
      <<"\n-----------------------------------------\n"
      <<"[1]> Show Clients\n"
      <<"[2]> Add New Clients\n"
      <<"[3]> Update Client\n"
      <<"[4]> Delete Client\n"
      <<"[5]> Find Client\n"
      <<"[6]> Transactions\n"
      <<"[7]> Exit\n"
      <<"-----------------------------------------\n\n";
  cout<<endl;
}

void onExit()
{
  exit(EXIT_FAILURE);
}


bool getApproval(char getApproval)
{
  return (getApproval == 'y' || getApproval == 'Y');
}

vector <string> deleteClient(string AccNumber, string filename="Clients/Data")
{
  stClients Client;
  char approval;
  vector <string> vRecs;
  vector <stClients> vClients;
  vRecs = loadRecsToVec(filename);
  vClients = convertRecs(vRecs, Client);

  approval = char(prompt("Are you sure you want to delete this account?(Y/N)  ")[0]);
  
  if (getApproval(approval) == false) {
    onTrigger();
  }else{
    vRecs.clear();
    
    for (stClients &C:vClients) {
      if (AccNumber == C.AccountNumber) {
	continue;
      }
      vRecs.push_back(convertToLine(C));
    }
    vClients.clear();
  }
  
  return (vRecs);
}

vector <stClients> updateFile(vector <string> &vRecs, const string filename)
{
  fstream file;
  stClients Client;
  vector <stClients> vClients;
  
  file.open(filename, ios::out);

  if (file.is_open()) {

    for (const string &rec : vRecs) {
      Client = restructRec(splitString(rec));
      vClients.push_back(Client);
      file<<rec<<'\n';
    }
    file.close();
  }

  return (vClients);
}

vector <string> updateClient(string AccNumber, string filename="Clients/Data", bool open=false)
{
  char approval;
  vector <string> vRecs;
  vector <stClients> vClients;
  
  vRecs = loadRecsToVec(filename);
  vClients = updateFile(vRecs, filename);

  if (open == true) {
    approval = char(prompt("Are you sure you want to update this account?(Y/N)  ")[0]);
  }
  
  if (getApproval(approval) == false) {
    onTrigger();
  }else{
    vRecs.clear();
    
    for (stClients &C:vClients) {
      if (AccNumber == C.AccountNumber) {
	cout<<"Updating Account Number ("<<AccNumber<<") Client details...\n\n";
	C = readClientData(true);
	C.AccountNumber = AccNumber;
      }
      vRecs.push_back(convertToLine(C));
    }
    
    vClients = updateFile(vRecs, filename);
  }
  
  return (vRecs);
}

vector <string> getAccNumbers()
{
  vector <string> vAccNums;
  vector <string> vRecs;
  short pos;

  vRecs = loadRecsToVec("Clients/Data");
  
  for (const string &AccNums : vRecs) {
    pos = AccNums.find("#/\\#");
    vAccNums.push_back(AccNums.substr(0, pos));
  }

  return (vAccNums);
}

bool doesExist(string AccNumber)
{
  vector <string> vAccNums = getAccNumbers();

  for (const string &Acc : vAccNums) {
    if (AccNumber == Acc) {
      cout<<"This account number does already exist\n\nre-";
      return (true);
    }
  }

  return (false);
}

void transactionsMenuDisplay()
{
  cout<<"-----------------------------------------\n"
      <<setw(30)<<"Transactions Menu"
      <<"\n-----------------------------------------\n"
      <<"[1]> Deposit\n"
      <<"[2]> Withdraw\n"
      <<"[3]> Total Balance\n"
      <<"[4]> Main Menu\n"
      <<"-----------------------------------------\n\n";
  cout<<endl;
}

string isValid(uint16_t &amount, stClients &Client, const char *Msg, string filename="Clients/Data")
{
  string AccNumber;
  
    do {
      AccNumber = prompt("Enter the account number: ");
      printClient(AccNumber, Client);
    
      if (AccNumber == Client.AccountNumber) {
	amount = stod(prompt(Msg));
      }
    } while (!findClient(AccNumber, Client, filename));

    return (AccNumber);
}

void printTransactionMsg(uint16_t amount, string AccNumber, vector <stClients> vClients, const string Msg)
{
  for (const stClients &c:vClients) {
    if (AccNumber == c.AccountNumber) {
      cout<<Msg<<": ["<<amount<<"]\n";
      cout<<"Your account balance is: ["<<c.AccountBalance<<"]\n";
      cout<<"Account balance has been updated successfully\n"<<endl;
      break;
    }
  }
}

vector <string> depositInterface(string filename="Clients/Data")
{
  stClients Client;
  vector <stClients> vClients;
  vector <string> vRecs;
  uint16_t amount;
  string AccNumber;
  
  vRecs = loadRecsToVec(filename);
  vClients = updateFile(vRecs, filename);
  AccNumber = isValid(amount, Client, "Enter the amount you want to deposit: ");
  
  while (amount < 100) {
    cout<<"Amount is too low, it should be greater than or equal 100\n";
    amount = stod(prompt("re-Enter the amount you want to deposit: "));
  }

  if (amount >= 100) {
    char approval;
    
    approval = char(prompt("Are you sure you want to perfom this transaction? (Y/N): ")[0]);

    if (getApproval(approval) == false) {
      transactionsMenuDisplay();
    } else {
      vRecs.clear();
      
      for (stClients &c:vClients) {
	if (c.AccountNumber == AccNumber) {
	  c.AccountBalance += amount;
	}
	vRecs.push_back(convertToLine(c));
      }
      vClients = updateFile(vRecs, filename);
    }
    printTransactionMsg(amount, AccNumber, vClients, "\nYou have successfully deposited");
  }

  return (vRecs);
}

vector <string> withdrawInterface(string filename="Clients/Data")
{
  stClients Client;
  vector <stClients> vClients;
  vector <string> vRecs;
  uint16_t amount;
  string AccNumber;
  
  vRecs = loadRecsToVec(filename);
  vClients = updateFile(vRecs, filename);
  AccNumber = isValid(amount, Client, "Enter the amount you want to withdraw: ");
  
  while (amount > Client.AccountBalance) {
    cout<<"The entered amount ("<<amount<<") exceeds this account balance ("<<Client.AccountBalance<<")\n";
    amount = stod(prompt("re-Enter the amount you want to withdraw\n(make sure it doesn't exceed the account balance): "));
    
  }

  if (amount < Client.AccountBalance) {
    char approval;
    
    approval = char(prompt("Are you sure you want to perfom this transaction? (Y/N): ")[0]);

    if (getApproval(approval) == false) {
      transactionsMenuDisplay();
    } else {
      vRecs.clear();
      
      for (stClients &c:vClients) {
	if (c.AccountNumber == AccNumber) {
	  c.AccountBalance -= amount;
	}
	vRecs.push_back(convertToLine(c));
      }
      vClients = updateFile(vRecs, filename);
    }

    printTransactionMsg(amount, AccNumber, vClients, "\nYou have successfully withdrawn");
  }

  return (vRecs);
}

void tableHeader(uint16_t count)
{
  cout<<"\n\t\t\t\tBalances List ["<<count<<"]Client(s)\n\n";
  cout<<"____________________________________________________"
      <<"_____________________________________________\n\n"
      <<" | Account Number"<<setw(22)
      <<" | Fullname"<<setw(45)
      <<" | Account Balance"<<'\n'
      <<"____________________________________________________"
      <<"_____________________________________________\n";
}

void tableCore(stClients Client)
{
  cout<<" | "<<Client.AccountNumber<<setw(24)
      <<" | "<<spacer(Client.Fullname, 35)
      <<" | "<<Client.AccountBalance<<'\n';
}

void displayBalanceTable(string filename="Clients/Data")
{
  vector <string> vRecs;
  vector <stClients> vClients;
  vector <stClients>::iterator iter;
  double TotalBalance{0.0};

  vRecs = loadRecsToVec(filename);
  vClients = updateFile(vRecs, filename);

  tableHeader(vClients.size());
  
  for (iter = vClients.begin(); iter != vClients.end(); iter++) {
    tableCore(*iter);
    TotalBalance += double((*iter).AccountBalance);
  }

  cout<<"____________________________________________________"
      <<"_____________________________________________\n"
      <<"\n\t\t\t\t  Total Balance [$ "<<to_string(TotalBalance)<<"]\n"
      <<"____________________________________________________"
      <<"_____________________________________________\n"<<endl;
}

void transactionsHandler(uint16_t operationChoice)
{
  enTrx Trx;
  
  operationChoice = stoi(prompt("Choose an option: "));
  
  switch (Trx = (enTrx)operationChoice)
  {
  case (enTrx::Deposit):
    depositInterface();
    break;
  case (enTrx::Withdraw):
    withdrawInterface();
    break;
  case (enTrx::Balance):
    displayBalanceTable();
    break;
  case (enTrx::MainMenu):
    onTrigger();
    break;
  default:
    cout<<"Not an option\n";
    break;
  }
}

void funcsSwitcher(uint16_t &operationChoice)
{
  enFuncs funcs;
  stClients Client;
  vector <string> vRecs;
  vector <stClients> vClients;
  string filename = "Clients/Data";
  string AccNumber;
  
  switch (funcs = (enFuncs)operationChoice)
  {
  case (enFuncs::Display):
    DisplayAllClient();
    break;
  case (enFuncs::Insert):
    cout<<"Adding New client window:\n\n";
    vClients = vecFillerWithClients(Client);
    vRecs = saveRecs(vClients);
    saveRecordsToFile(vRecs, filename);
    break;
  case (enFuncs::Update):
    do {
      AccNumber = prompt("Enter the account number: ");
      printClient(AccNumber, Client);
    } while (findClient(AccNumber, Client) == false);
    vRecs = updateClient(AccNumber, filename, true);
    cout<<"\n\nClient details have been successfully updated\n"<<endl;
    break;
  case (enFuncs::Delete):
    do {
      AccNumber = prompt("Enter the account number: ");
      printClient(AccNumber, Client);
    } while (findClient(AccNumber, Client) == false);
    vRecs = deleteClient(AccNumber);
    cout<<"\nClient with the account number ("<<AccNumber<<") has been deleted\n"<<endl;
    vClients = updateFile(vRecs, filename);
    break;
  case (enFuncs::Find):
    AccNumber = prompt("Enter the account number: ");
    findClient(AccNumber, Client);
    printClient(AccNumber, Client);
    break;
  case (enFuncs::Transaction):
    while (operationChoice != 0) {
      transactionsMenuDisplay();
      transactionsHandler(operationChoice);
    }
    break;
  case (enFuncs::Exit):
    onExit();
    break;
  default:
    cout<<"Operation is non-existant\n\n";
    break;
  }
}

void onTrigger()
{
  uint16_t operationChoice;
  
  while (true) {
    mainMenuDisplay();
    operationChoice = stoi(prompt("Enter your choice? "));
    funcsSwitcher(operationChoice);
    
    while (operationChoice >= 1 && operationChoice <= 7) {
      operationChoice = stoi(prompt("Hit [0] to go back...  "));
      if (operationChoice == 0)
	break;
    }
    
    if (operationChoice == 7)
      onExit();
  }
}
