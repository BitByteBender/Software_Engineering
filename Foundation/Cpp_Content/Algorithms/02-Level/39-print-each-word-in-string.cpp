#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

string readText(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin, Text);

  return (Text);
}

void printText(string Text)
{
  string delim = " ";
  cout<<"\nyour string words are: \n\n";
  short pos = 0;
  string sWord;
  
  while ((pos = Text.find(delim)) != string::npos) {

    sWord = Text.substr(0, pos);

    if (sWord != " ") {
      cout<<sWord<<'\n';
    }
    Text.erase(0, pos + delim.length());
  }

  if (Text != " ") {
    cout<<Text<<endl;
  }
}

int main(void)
{
  string Text = readText("Enter a text:\n");

  printText(Text);
  
  return (0);
}
