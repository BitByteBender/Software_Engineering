#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ios;

struct stClientData
{
  string AccountNumber;
  uint16_t PinCode{0};
  string Fullname;
  string PhoneNumber;
  double AccountBalance{0.0f};
};

void displayHeader(uint16_t counter)
{
  cout<<"\t\t\t\t\tClient list ("<<counter<<") Client(s).\n\n";

  cout<<"------------------------------------------------------"
      <<"----------------------------------------------------\n"
      <<"| Account Number\t"
      <<"| Pin code\t"
      <<"| Full name\t\t"
      <<"| Phone Number\t\t"
      <<"| Account Balance"
      <<"\n----------------------------------------------------"
      <<"------------------------------------------------------\n";
}

vector <string> retrieveRecords(const string Filename)
{
  fstream File;
  vector <string> vRecs;
  
  File.open(Filename, ios::in);

  if (File.is_open()) {
    string line;

    while (getline(File, line)) {
      if (!line.empty()) {
	vRecs.push_back(line);
      }
    }
    File.close();
  }

  return (vRecs);
}

void splitline(vector <string> &vRecs, string matrixRecs[3][5])
{
  const string DELIM="#//#";
  
  unsigned i = 0, j = 0;
  
  for (const string &Records : vRecs) {
    string Text = Records;
    short pos = Text.find(DELIM);

    while (pos != string::npos) {
      matrixRecs[i][j] = Text.substr(0, pos);
      Text.erase(0, pos + DELIM.length());
      pos = Text.find(DELIM);
      ++j;
    }
    if (!Text.empty()) {
      matrixRecs[i][j] = Text;
      Text.clear();
    }
    j = 0;
    i++;
  }

}

void storeClientsData(stClientData Clients[3], uint16_t &ClientCount, string matrixRecs[3][5])
{
  unsigned short i = 0;
  
  for (i = 0; i < ClientCount; i++) {
    Clients[i].AccountNumber = matrixRecs[i][0];
    Clients[i].PinCode = stoi(matrixRecs[i][1]);
    Clients[i].Fullname = matrixRecs[i][2];
    Clients[i].PhoneNumber = matrixRecs[i][3];
    Clients[i].AccountBalance = stod(matrixRecs[i][4]);
  }
}

string spacer(string word)
{
  unsigned short i = 0, Count = 15 - word.length();
  string spaceHolder;
  
  for (i = 0; i <= Count; ++i) {
    spaceHolder += ' ';
  }

  return (spaceHolder);
}

void displayClients(stClientData Clients[3], uint16_t ClientCount)
{
  unsigned short i = 0;

  displayHeader(ClientCount);
  
  for (i = 0; i < ClientCount; i++) {
    cout<<"| "<<std::setw(3)<<Clients[i].AccountNumber<<"\t\t\t"
	<<"| "<<Clients[i].PinCode<<"\t\t"
	<<"| "<<Clients[i].Fullname<<spacer(Clients[i].Fullname)<<'\t'
	<<"| "<<Clients[i].PhoneNumber<<"\t"
	<<"| "<<Clients[i].AccountBalance<<'\n';
  }
  cout<<"----------------------------------------------------"
      <<"------------------------------------------------------"<<endl;
}

  int main(void)
{
  stClientData Clients[3];
  vector <string> vClient;
  uint16_t ClientCount = 3;
  const uint16_t rows = 3, cols = 5;
  string matrixRecs[rows][cols];
  
  const string Filename = "Clients/Data";
  
  vClient = retrieveRecords(Filename);

  splitline(vClient, matrixRecs);

  storeClientsData(Clients, ClientCount, matrixRecs);
  displayClients(Clients, ClientCount);
  return (0);
}
