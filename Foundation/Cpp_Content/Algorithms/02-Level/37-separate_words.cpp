#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string readText(const char *Msg)
{
  string Text{"Empty"};

  cout<<Msg;
  getline(cin, Text);

  return (Text);
}

inline bool checkSpace(char Character)
{
  return (Character == ' ');
}

void printWordsSeparated(string Text, const char *Msg)
{
  uint16_t i = 0;
  
  cout<<Msg;
  
  for (i = 0; i < Text.length(); i++) {
    if (!checkSpace(Text[i]))
      cout<<Text[i];
    else
      cout<<'\n';
  }
  
  cout<<endl;
}

int main(void)
{
  string Text = readText("Enter a text to check:\n");
  printWordsSeparated(Text, "your string in separated words are:\n");
  return (0);
}
