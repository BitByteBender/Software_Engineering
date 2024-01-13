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

void printUppercase(string Text, const char *Msg)
{
  uint16_t i = 0;

  cout<<Msg;
  
  for (i = 0; i < Text.length(); i++) {
    if (isLowerAlphabet(Text[i]))
      cout<<toUpper(Text[i]);
    else
      cout<<Text[i];
  }
  cout<<endl;
}

void printLowercase(string Text, const char *Msg)
{
  uint16_t i = 0;

  cout<<Msg;
  
  for (i = 0; i < Text.length(); i++) {
    if (isUpperAlphabet(Text[i]))
	cout<<toLower(Text[i]);
    else
      cout<<Text[i];
  }
  cout<<endl;
}

int main(void)
{
  string Text = readText("Enter a text: ");
  printUppercase(Text, "lower to upper(string):\n");
  cout<<'\n';
  printLowercase(Text, "upper to lower(string):\n");
  return (0);
}
