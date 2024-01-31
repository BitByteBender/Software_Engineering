#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ios;
using std::ws;
using std::to_string;

struct stClients
{
  string AccountNumber;
  uint16_t PinCode{0};
  string Fullname;
  string PhoneNumber;
  double AccountBalance{0.0f};
};

string promptReader(const char *Msg)
{
  string prompt{"empty"};

  cout<<Msg;
  getline(cin >> ws, prompt);

  return (prompt);
}

vector <string> splitString(string str, string delim="#//#")
{
  vector <string> vString;
  short pos = 0;

  while ((pos = str.find(delim)) != string::npos) {
    vString.push_back(str.substr(0, pos));
    str.erase(0, pos + delim.length());
  }

  if (!str.empty()) {
    vString.push_back(str);
    str.clear();
  }

  return (vString);
}

stClients loadRec(string rec)
{
  stClients Client;
  vector <string> vString = splitString(rec);
  
  Client.AccountNumber = vString[0];
  Client.PinCode = stoi(vString[1]);
  Client.Fullname = vString[2];
  Client.PhoneNumber = vString[3];
  Client.AccountBalance = stod(vString[4]);
  
  return (Client);
}

vector <stClients> loadClients()
{
  vector <stClients> vClients;
  fstream file;
  
  file.open("Clients/Data", ios::in);

  if (file.is_open()) {
    string line;
    stClients Client;
    while (getline(file, line)) {
      Client = loadRec(line);
      vClients.push_back(Client);
    }
    file.close();
  }

  return (vClients);
}

bool checkAccNum(string AccNum, stClients &Client)
{
  vector <stClients> vClients;
  vClients = loadClients();

  for (const stClients &C : vClients) {
    if (AccNum == C.AccountNumber) {
      Client = C;
      return (true);
    }
  }

  return (false);
}

void printCard(string AccNum, stClients Client)
{
  if (checkAccNum(AccNum, Client)) {
    cout<<"\n\nThe following are the client's details\n\n";
    cout<<"Account Number: "<<Client.AccountNumber<<'\n';
    cout<<"Pin Code: "<<Client.PinCode<<'\n';
    cout<<"Fullname: "<<Client.Fullname<<'\n';
    cout<<"Phone Number: "<<Client.PhoneNumber<<'\n';
    cout<<"Account Balance: "<<Client.AccountBalance<<endl;
  } else {
    cout<<"Client with this account number ("<<AccNum<<") is not found!"<<endl;
    exit(EXIT_FAILURE);
  }
}

stClients updateClient(stClients &Client)
{
 
  Client.PinCode = stoi(promptReader("Enter new pin code: "));
  Client.Fullname = promptReader("Enter new fullname: ");
  Client.PhoneNumber = promptReader("Enter new phone number: ");
  Client.AccountBalance = stod(promptReader("Enter new account balance: "));

  return (Client);
}

string formatRecs(stClients Client, string delim="#//#")
{
  string Record;

  Record += Client.AccountNumber + delim;
  Record += to_string(Client.PinCode) + delim;
  Record += Client.Fullname + delim;
  Record += Client.PhoneNumber + delim;
  Record += to_string(Client.AccountBalance);

  return (Record);
}


bool performUpdate(vector <string> &vRecs, char operation, stClients &Client)
{
  if (operation == 'Y' || operation == 'y') {
    Client = updateClient(Client);
    vRecs.push_back(formatRecs(Client));
    return (true);
  }

  return (false);
}

vector <string> rSafe(string AccNum, char operation)
{
  vector <stClients> vClients = loadClients();
  vector <string> vRecs;
  
  for (stClients &C : vClients) {
    if ((AccNum == C.AccountNumber)) {
      performUpdate(vRecs, operation, C);
    } else {
      vRecs.push_back(formatRecs(C));
    } 
  }

  return (vRecs);
}

void updateFile(vector <string> &vRecs)
{
  fstream file;
  file.open("Clients/Data", ios::out);
  
  if (file.is_open()) {
    if (!vRecs.empty()) {
      for (string &Recs : vRecs) {
	file<<Recs<<'\n';
      }
    } else {
      cout<<"vector is empty"<<'\n';
    }
    
    file.close();
  }
}

int main(void)
{
  stClients Client;
  vector <string> vRecs;
  string AccNum;
  char operation;

  AccNum = promptReader("Enter client account number: ");
  printCard(AccNum, Client);
  
  operation = promptReader("Are you sure you want to update this client's account(Y/N): ")[0];
  vRecs = rSafe(AccNum, operation);
  updateFile(vRecs);

  return (0);
}
