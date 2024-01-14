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

char readChar(const char *Msg)
{
  char Letter{'x'};

  cout<<Msg;
  cin>>Letter;

  return (Letter);
}

inline char toLower(char letter)
{
  return (char(uint16_t(letter) + 32));
}

inline bool checkVowel(string str, char Letter, uint16_t pos)
{
  return (str[pos] == Letter || str[pos] == toLower(Letter));
}

bool isVowel(char Letter)
{
  string str = "aeiou";
  uint16_t i = 0;

  for (i = 0; i < str.length(); i++) {
    if (checkVowel(str, Letter, i))
      return (true);
  }

  return (false);
}

void printResult(char Letter)
{
  if (isVowel(Letter))
    cout<<"Yes letter '"<<Letter<<"' is a vowel."<<endl;
  else
    cout<<"No letter '"<<Letter<<"' is a consonant."<<endl;
}

int main(void)
{
  char Letter = readChar("Enter a character that you want to check: ");

  printResult(Letter);
  return (0);
}
