#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

char readLetter(const char *Msg)
{
  char Letter{'x'};

  cout<<Msg;
  cin>>Letter;

  return (Letter);
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

inline char invertLetter(char letter)
{
  return (isLowerAlphabet(letter) ? toUpper(letter) : toLower(letter));
}

void printInverted(char letter, const char *Msg)
{
  cout<<Msg;
  cout<<invertLetter(letter);
  cout<<endl;
}

int main(void)
{
  char letter = readLetter("Enter a letter: ");
  cout<<'\n';
  printInverted(letter, "inverted:\n");
  return (0);
}
