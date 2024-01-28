#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

struct stClientRecord
{
  string AccountNumber;
  uint16_t PinCode;
  string Fullname;
  string PhoneNumber;
  double AccountBalance;
};

vector <string> splitLine(string line, string seperator="#//#")
{
  vector <string> vRecords;
  short pos = line.find(seperator);

  while (pos != string::npos) {
    vRecords.push_back(line.substr(0, pos));
    line.erase(0, pos + seperator.length());
    pos = line.find(seperator);
  }

  if (!line.empty()) {
    vRecords.push_back(line);
    line.clear();
  }
  
  return (vRecords);
}

stClientRecord fillClientRecord(vector <string> &vRecord)
{
  stClientRecord Client;

  Client.AccountNumber = vRecord.at(0);
  Client.PinCode = stoi(vRecord.at(1));
  Client.Fullname = vRecord.at(2);
  Client.PhoneNumber = vRecord.at(3);
  Client.AccountBalance = stod(vRecord.at(4));
  
  return (Client);
}

void PrintClientRecord(stClientRecord Client, string lineRecord)
{
  cout<<"Line Record: "<<lineRecord<<"\n\n";
  cout<<"Account Number: "<<Client.AccountNumber<<'\n';
  cout<<"Pin code: "<<Client.PinCode<<'\n';
  cout<<"Fullname: "<<Client.Fullname<<'\n';
  cout<<"Phone Number: "<<Client.PhoneNumber<<'\n';
  cout<<"Account Balance: "<<Client.AccountBalance<<endl;;
}

int main(void)
{
  stClientRecord Client;
  string lineRecord;
  vector <string> vRecord;

  lineRecord = "T999#//#7825#//#Soufiane Bot#//#+999-589 69 96 05#//#9999.000000";
  vRecord = splitLine(lineRecord);
  Client = fillClientRecord(vRecord);
  PrintClientRecord(Client, lineRecord);
  
  return (0);
}
