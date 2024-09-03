#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::to_string;
using std::ws;

struct stDate
{
  uint16_t Day, Month, Year;
};

string ReadText(const char *Message)
{
  string Text{"empty"};

  cout<<Message;
  getline(cin >> ws, Text);
  
  return (Text);
}

string SplitText(string Text)
{
  uint16_t i = 0;
  string strContainer;

  for (; i <= (Text.length() - 1); ++i) {
    if (Text[i] != '/') strContainer += Text[i];
    else return (strContainer);
  }
}

stDate LoadRec(string Text)
{
  stDate Date;
  string strContainer = SplitText(Text);
  
  Date.Day = stoi(strContainer);

  Text = Text.substr(strContainer.length() + 1);
  strContainer = SplitText(Text);
  Date.Month = stoi(strContainer);

  Text = Text.substr(strContainer.length() + 1);
  Date.Year = stoi(Text);
  
  return (Date);
}

inline string DateToString(stDate Date, char DELIMITER)
{
  return (to_string(Date.Day) + DELIMITER + to_string(Date.Month) + DELIMITER + to_string(Date.Year));
}

int main(void)
{
  string Text = ReadText("Enter a Date dd/mm/yyyy: ");
  stDate Date = LoadRec(Text);

  cout<<"\nDay: "<<Date.Day<<"\nMonth: "<<Date.Month<<"\nYear: "<<Date.Year<<endl;
  cout<<"\nYou Entered: "<<DateToString(Date, '/')<<endl;
  
  return (0);
}
