#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string readText(const char *Msg)
{
  string Txt;

  cout<<Msg;
  getline(cin, Txt);

  return (Txt);
}

uint16_t countWords(string Text)
{

  string sWord, delim = " ";
  short pos = 0, Total = 0;

  while ((pos = (Text.find(delim))) != string::npos) {
    sWord = Text.substr(0, pos);

    if (sWord != "") {
      Total++;
    }

    Text.erase(0, pos + delim.length());
  }

  if (sWord != "") {
    Total++;
  }

  
  return (Total);
}

void printTotalWordCount(uint16_t total)
{
  cout<<"The total number of words in the string: "<<total<<endl;
}

int main(void)
{
  string Txt = readText("Enter a text:\n");

  printTotalWordCount(countWords(Txt));
  return (0);
}
