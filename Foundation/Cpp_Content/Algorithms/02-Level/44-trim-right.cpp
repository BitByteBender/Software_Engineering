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

string trimRight(string Text, char DELIMITER)
{
  short pos = Text.length() - 1;
  string sWord;

  while (Text.at(pos) == DELIMITER) {
    pos--;
  }

  sWord = Text.substr(0, pos);
  return (sWord);
}

void printTrimmedText(string TrimmedText)
{
  cout<<TrimmedText<<endl;
}

int main(void)
{
  string Text = readText();

  printTrimmedText(trimRight(Text, ' '));
  return (0);
}
