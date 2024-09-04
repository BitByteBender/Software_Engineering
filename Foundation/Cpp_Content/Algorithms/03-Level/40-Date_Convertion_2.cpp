#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::ws;
using std::vector;

struct stDate
{
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

string ReadString(const char *Msg)
{
  string Text;

  cout<<Msg;
  getline(cin >> ws, Text);
  
  return (Text);
}

vector <uint16_t> SplitString(string Text, char DELIMITER)
{
  vector <uint16_t> vecText;
  short pos = Text.find(DELIMITER);

  while (pos != short(string::npos)) {
    vecText.push_back(stoi(Text.substr(0, pos)));
    Text.erase(0, pos + 1);
    pos = Text.find(DELIMITER);
  }

  if (!Text.empty()) {
    vecText.push_back(stoi(Text));
    Text.clear();
  }

  return (vecText);
}

stDate LoadData(string Text)
{
  stDate Date;
  vector <uint16_t> vecText = (SplitString(Text, '/'));

  Date.Day = vecText[0];
  Date.Month = vecText[1];
  Date.Year = vecText[2];

  return (Date);
}

string DateToString(stDate Date)
{
  return (to_string(Date.Day) + '/' + to_string(Date.Month) + '/' + to_string(Date.Year));
}

int main(void)
{
  string Text = ReadString("Enter a date in this format(DD/MM/YYYY): ");
  stDate Date = LoadData(Text);

  cout<<"\nDay: "<<Date.Day<<"\nMonth: "<<Date.Month<<"\nYear: "<<Date.Year<<endl;

  cout<<"\nYou Entered: "<<DateToString(Date)<<endl;
  return (0);
}
