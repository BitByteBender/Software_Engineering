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

string replaceWord(string Text, string rWord, string newWord)
{
  string newStr;
  short pos = Text.find(rWord);

  while (pos != std::string::npos) {

    newStr += Text.substr(0, pos);
    newStr += newWord;

    Text = Text.erase(0, pos + rWord.length());
    pos = Text.find(rWord);
  }

  if (Text != "") {
    newStr += Text;
  }

  return (newStr);
}

void printText(string Text)
{
  cout<<Text<<endl;
}

int main(void)
{
  string Text = readText("Enter a text:\n");
  string rWord = readText("You want to truncate: ");
  string newWord = readText("with: ");
  
  printText(replaceWord(Text, rWord, newWord));
  
  return (0);
}
