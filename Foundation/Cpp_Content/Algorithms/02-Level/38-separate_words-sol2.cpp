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

string reformatText(string Text)
{
  uint16_t i = 0;
  string str;
  
  for (i = 0; i < Text.length(); i++) {
    if (!checkSpace(Text[i]))
      str += Text[i];
    else if (!checkSpace(Text[i - 1]) && checkSpace(Text[i]))
      str += '\n';
  }
  
  return (str);
}

void printWordsSeparated(string Text)
{
  cout<<"your string in separated words are:\n"<<reformatText(Text)<<endl;
}

int main(void)
{
  string Text = readText("Enter a text to check:\n");
  printWordsSeparated(Text);
  
  return (0);
}
