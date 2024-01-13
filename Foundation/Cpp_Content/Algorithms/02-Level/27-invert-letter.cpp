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

void printInverted(char Letter, const char *Msg)
{
  cout<<Msg;

  if (isLowerAlphabet(Letter)) {
    cout<<toUpper(Letter);
  }
  else {
    cout<<toLower(Letter);
  }
  cout<<endl;
}

int main(void)
{
  char letter = readLetter("Enter a letter: ");
  cout<<'\n';
  printInverted(letter, "inverted:\n");
  return (0);
}
