#include <iostream>

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

inline char toUpper(char letter)
{
  return (char(uint16_t(letter) - 32));
}

inline char toLower(char letter)
{
  return (char(uint16_t(letter) + 32));
}

inline bool isUpper(char letter)
{
  return (letter >= 65 && letter <= 90);
}

inline char isLower(char letter)
{
  return (isUpper(letter) ? toLower(letter) : toUpper(letter));
}

inline char isAlphabetOrSpace(string Text, uint16_t pos)
{
  return (Text[pos] != ' ' ? isLower(Text[pos]) : ' ');
}

void printInvertedText(string Text, const char *Msg)
{
  cout<<Msg;
  uint16_t i = 0;
  
  for (i = 0; i < Text.length(); i++) {
    cout<<isAlphabetOrSpace(Text, i);
  }
  cout<<endl;
}

int main(void)
{
  string Text = readText();
  printInvertedText(Text, "String after inverting all letters cases:\n");
  return (0);
}

