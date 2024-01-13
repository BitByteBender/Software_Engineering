#include <iostream>

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

inline char toUpper(char alphabet)
{
  return (char(uint16_t(alphabet) - 32));
}

inline char toLower(char alphabet)
{
  return (char(uint16_t(alphabet) + 32));
}

inline bool isLowerAlphabet(char letter)
{
  return (letter >= char(97) && letter <= char(122));
}

inline bool isUpperAlphabet(char letter)
{
  return (letter >= char(65) && letter <= char(90));
}

string toUppercase(string Text)
{
  uint16_t i = 0;
  
  for (i = 0; i < Text.length(); i++) {
    if (isLowerAlphabet(Text[i]))
      Text[i] = toUpper(Text[i]);
  }
  return (Text);
}

string toLowercase(string Text)
{
  uint16_t i = 0;
  
  for (i = 0; i < Text.length(); i++) {
    if (isUpperAlphabet(Text[i]))
      Text[i] = toLower(Text[i]);
  }
  return (Text);
}

void printString(string Text, const char *Msg)
{
  uint16_t i = 0;

  cout<<Msg;
  
  for (i = 0; i < Text.length(); i++) {
    cout<<Text[i];
  }
  cout<<endl;
}

int main(void)
{
  string Text = readText("Enter a text: ");
  cout<<'\n';
  printString(toUppercase(Text), "lower to upper(string):\n");
  cout<<'\n';
  printString(toLowercase(Text), "upper to lower(string):\n");
  return (0);
}
