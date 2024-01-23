#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string readText()
{
  string Text{"empty"};

  cout<<"Enter a text: ";
  getline(cin, Text);

  return (Text);
}

string trimLeft(string Text, char DELIMITER)
{
  short pos = 0;
  string sWord;

  while (Text.at(pos) == DELIMITER) {
    pos++;
  }

  sWord = Text.substr(pos, Text.length());
  return (sWord);
}

void printTrimmedText(string TrimmedText)
{
  cout<<TrimmedText<<endl;
}

int main(void)
{
  string Text = readText();

  printTrimmedText(trimLeft(Text, ' '));
  return (0);
}
