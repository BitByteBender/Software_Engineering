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
  Display = 0,
  Insert = 1,
  Update = 2,
  Delete = 3,
  Find = 4,
  Exit = 5
};

struct stClients
{
  string AccountNumber;
  uint16_t PinCode;
  string Fullname, PhoneNumber;
  double AccountBalance;
};

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

stClients readClientData()
{
  stClients Client;
  string AccBalance;
  
  cout<<"Adding New client window:\n\n";
  
  do {
    Client.AccountNumber = prompt("Enter an account number: ");
  } while (!isUpper(Client.AccountNumber[0]) || wordCounter(Client.AccountNumber) < 4);

  Client.PinCode = stoi(prompt("Enter a pin code: "));
  
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
    Client = readClientData();
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

vector <string> saveRecs(stClients &Client)
{
  vector <stClients> vClients = vecFillerWithClients(Client);
  vector <string> vRecs;

  for (const stClients &C : vClients) {
    vRecs.push_back(convertToLine(C));
  }

  return (vRecs);
}

void saveRecordsToFile(vector <string> vRecs, const string filename)
{
  fstream file;
  
  file.open(filename, ios::out);

  if (file.is_open()) {
    for (const string &Rec : vRecs) {
      file<<Rec<<'\n';
    }
    file.close();
  }
}

vector <string> loadRecsToVec(vector <string> &vRecs, const string filename)
{
  fstream file;

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

vector <stClients> convertRecs(vector <stClients> &vClients, vector <string> &vRecs, stClients &Client)
{

  for (const string &rec : vRecs) {
    Client = restructRec(splitString(rec));
    vClients.push_back(Client);
  }

  return (vClients);
}

void tableHeader(uint16_t &count)
{
  cout<<"\nCurrent Clients Regsitered count("<<count<<")\n\n";
  cout<<"____________________________________________________"
      <<"___________________________________________________\n"
      <<" | Account Number"<<setw(13)
      <<" | Pin Code"<<setw(17)
      <<" | Fullname"<<setw(25)
      <<" | Phone Number"<<'\t'
      <<" | Account Balance"<<'\n'
      <<"____________________________________________________"
      <<"____________________________________________________\n";
}

void printClients(stClients Client)
{
  cout<<"Account number: "<<Client.AccountNumber<<'\n';
  cout<<"Pin code: "<<Client.PinCode<<'\n';
  cout<<"Fullname: "<<Client.Fullname<<'\n';
  cout<<"Phone number: "<<Client.PhoneNumber<<'\n';
  cout<<"Account balance: "<<Client.AccountBalance<<endl;
}

string spacer(string text)
{
  uint16_t i = 0, count = 21;
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
  cout<<" | "<<spacer(Client.Fullname);
  cout<<" | "<<Client.PhoneNumber<<"\t";
  cout<<" | "<<Client.AccountBalance<<endl;
}

void DisplayAllClient(vector <stClients> &vClients)
{
  uint16_t count;
  vector <stClients>::iterator iter;
  
  tableHeader((count = vClients.size()));
  
  for (iter = vClients.begin(); iter != vClients.end(); iter++) {
    showClients(*iter);
  }
  cout<<endl;
}

int main(void)
{
  stClients Client;
  vector <stClients> vClients;
  vector <string> vRecs;
  const string filename{"Clients/Data"};


  vRecs = saveRecs(Client);
  saveRecordsToFile(vRecs, filename);


  vClients = convertRecs(vClients, vRecs, Client);
  
  for (const stClients &C:vClients) {
    printClients(C);
  }
  
  return (0);
}
