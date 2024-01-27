#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

struct stPersonData
{
  string AccountNumber{"Z999"};
  uint16_t PinCode{0000};
  string ClientName{"firstName{\"empty\"} LastName{\"empty\"}"};
  string Phone{"empty"};
  double AccountBalance{0.0000};
};

string readText(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin, Text);

  return (Text);
}

double readNum(const char *Msg)
{
  double Num{0.0f};

  cout<<Msg;
  cin>>Num;

  return (Num);
}

void readPersonData(stPersonData &Person)
{
  Person.AccountNumber = readText("Enter Account Number: ");
  Person.PinCode = readNum("Enter Pin code: ");
  cin.ignore(1, '\n');
  Person.ClientName = readText("Enter Full Name: ");
  Person.Phone = readText("Enter Phone Number: ");
  Person.AccountBalance = readNum("Enter Account Balance: ");
}

string convertRecordIntoLine(stPersonData Person, string Delimiter="#//#")
{
  string dtRecord = "";
  
  dtRecord += Person.AccountNumber + Delimiter;
  dtRecord += to_string(uint16_t(Person.PinCode)) + Delimiter;
  dtRecord += Person.ClientName + Delimiter;
  dtRecord += Person.Phone + Delimiter;
  dtRecord += to_string(Person.AccountBalance);

  return (dtRecord);
}

void printConvertedRecord(string Record)
{
  cout<<Record<<endl;
}

int main(void)
{
  stPersonData Person;
  
  readPersonData(Person);
  printConvertedRecord(convertRecordIntoLine(Person));
  
  return (0);
}
