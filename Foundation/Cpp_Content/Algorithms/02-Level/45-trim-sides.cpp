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

  sWord = Text.substr(0, pos + 1);
  return (sWord);
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

string TrimSides(string Text, char DELIMITER)
{
  return (trimLeft(trimRight(Text, DELIMITER), DELIMITER));
}

void printTrimmedText(string TrimmedText)
{
  cout<<TrimmedText<<endl;
}

int main(void)
{
  string Text = readText();

  printTrimmedText(TrimSides(Text, ' '));
  return (0);
}
