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

vector <string> splitString(string str, string delim)
{
  vector <string> vString;
  short pos = str.find(delim);

  while (pos != string::npos) {
    vString.push_back(str.substr(0, pos));
    str.erase(0, pos + delim.length());
    pos = str.find(delim);
  }

  if (str != "") {
    vString.push_back(str);
    str.clear();
  }

  return (vString);
}

stClients saveData(vector <string> &vString)
{
  stClients Client;

  Client.AccountNumber = vString[0];
  Client.PinCode = stoi(vString[1]);
  Client.Fullname = vString[2];
  Client.PhoneNumber = vString[3];
  Client.AccountBalance = stod(vString[4]);
  
  return (Client);
}

vector <stClients> dataLoader(stClients &Client, string filename)
{
  vector <stClients> vClients;
  fstream ClientFile;

  ClientFile.open(filename, ios::in);

  if (ClientFile.is_open()) {
    string line;
    vector <string> vString;
    
    while (getline(ClientFile, line)) {
      vString = splitString(line, "#//#");
      Client = saveData(vString);
      vClients.push_back(Client);
    }
    ClientFile.close();
  }

  return (vClients);
}

bool checkClientData(string AccNum, stClients &Client)
{
  string filename;
  vector <stClients> vClients;
  
  filename = "Clients/Data";
  vClients = dataLoader(Client, filename);;

  for (const stClients &C : vClients) {
    if (AccNum == C.AccountNumber) {
      Client = C;
      return (true);
    }
  }

  return (false);
}

void printClientCard(string AccNum, stClients &Client)
{
  if (checkClientData(AccNum, Client)) {
    cout<<"\nThe following are the client's details:\n\n";
    cout<<"Account Number: "<<Client.AccountNumber<<'\n';
    cout<<"Pin Code: "<<Client.PinCode<<'\n';
    cout<<"Fullname: "<<Client.Fullname<<'\n';
    cout<<"Phone Number: "<<Client.PhoneNumber<<'\n';
    cout<<"Account Balance: "<<Client.AccountBalance<<'\n';
  } else {
    cout<<"Client with this account number ("<<AccNum<<") is not found!"<<endl;
    exit(EXIT_FAILURE);
  }
}

string joinString(stClients &Client)
{
  string line, delim = "#//#";

  line += Client.AccountNumber + delim;
  line += to_string(Client.PinCode) + delim;
  line += Client.Fullname + delim;
  line += Client.PhoneNumber + delim;
  line += to_string(Client.AccountBalance);

  return (line);
}

vector <string> deletion(string AccNum)
{
  stClients Client;
  
  vector <stClients> vOldClients;
  vector <string> vRecs;
  
  vOldClients = dataLoader(Client, "Clients/Data");

  for (stClients &C : vOldClients) {
    if (AccNum != C.AccountNumber) {
      vRecs.push_back(joinString(C));
    }
  }

  return (vRecs);
}

void updateRecord(string AccNum)
{
  fstream ClientFile;
  vector <string> vRecs = deletion(AccNum);
  ClientFile.open("Clients/Data", ios::out);

  if (ClientFile.is_open()) {
    if (!vRecs.empty()) {
      for (const string &Rec : vRecs)
	ClientFile<<Rec<<'\n';
    }
    ClientFile.close();
  }
}

bool isDeleted(string AccNum, char operation)
{
  if (operation == 'Y' || operation == 'y') {
    updateRecord(AccNum);
    return (true);
  }
  
  return (false);
}

void printUpdate(string AccNum, char operation)
{
  if (isDeleted(AccNum, operation)) {
    cout<<"Client Deleted successfully"<<endl;
  } else {
    cout<<"Operation has been cancelled"<<endl;
  }
}

int main(void)
{
  stClients Client;
  vector <stClients> vClients;
  string AccNum;
  char Operation;
  
  AccNum = promptReader("Enter client account number: ");
  printClientCard(AccNum, Client);

  Operation = promptReader("Are you sure you wanna delete this client's account (Y/N): ")[0];
  printUpdate(AccNum, Operation);
  
  return (0);
}
