#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::vector;
using std::fstream;
using std::ios;

struct stClientData
{
  string AccountNumber;
  uint16_t PinCode{0};
  string Fullname;
  string Phone;
  double AccountBalance{0.0f};
};

string readText(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin, Text);
  
  return (Text);
}

void readClientData(stClientData &Client)
{
  Client.AccountNumber = readText("Enter Account Number: ");
  Client.PinCode = stoi(readText("Enter Pin Code: "));
  Client.Fullname = readText("Enter full name: ");
  Client.Phone = readText("Enter phone: ");
  Client.AccountBalance = stod(readText("Enter account balance: "));
}

string convertRecord(stClientData Client, string DELIMITER="#//#")
{
  string sClient;

  sClient += Client.AccountNumber + DELIMITER;
  sClient += to_string(Client.PinCode) + DELIMITER;
  sClient += Client.Fullname + DELIMITER;
  sClient += Client.Phone + DELIMITER;
  sClient += to_string(Client.AccountBalance);
  
  return (sClient);
}

vector <string> saveClientRecords(stClientData &Client, char isRecording='N')
{
  vector <string> vClientRecs;

  cout<<"Record started...\n";
  
  do {
    readClientData(Client);
    vClientRecs.push_back(convertRecord(Client));
    isRecording = 'Y';
    
    cout<<"Client has been recorded successfully.\n";
    isRecording = char(readText("Do you wanna keep recording(Y or N)?: ").at(0));
  } while (isRecording == 'Y' || isRecording == 'y');

  return (vClientRecs);
}

void writeToFile(vector <string> vClientRecs, string Filename)
{
  fstream File;
  vector <string>::iterator iter;
  
  File.open(Filename, ios::out);

  if (File.is_open()) {
    for (iter = vClientRecs.begin(); iter != vClientRecs.end(); iter++) {
      File<<*iter<<'\n';
    }
    File.close();
  }
}

void displayFileRecs(string Filename)
{
  fstream File;
  
  File.open(Filename, ios::in);

  if (File.is_open()) {
    string line;

    while (getline(File, line)) {
	cout<<line<<endl;
    }
    File.close();
  }
}

int main(void)
{
  stClientData Client;
  vector <string> vClientRecs;
  string Filename = "Clients/Data";
  
  vClientRecs = saveClientRecords(Client);
  writeToFile(vClientRecs, Filename);

  cout<<"\n\nLine Records in file:\n\n";
  displayFileRecs("Clients/Data");
  
  return (0);
}
