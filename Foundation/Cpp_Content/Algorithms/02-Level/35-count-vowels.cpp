#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string readText(const char *Msg)
{
  string Text{"Empty"};

  cout<<Msg;
  getline(cin, Text);

  return (Text);
}

inline bool isLower(char alphabet)
{
  return (alphabet >= 97 && alphabet <= 122);
}

inline bool isUpper(char alphabet)
{
  return (alphabet >= 65 && alphabet <= 90);
}

char toLower(char alphabet)
{
  if (isLower(alphabet))
    return (alphabet);
  else
    return (char(uint16_t(alphabet) + 32));
}

char toUpper(char alphabet)
{
  if (isUpper(alphabet))
    return (alphabet);
  else
    return (char(uint16_t(alphabet) - 32));
}

inline char UpperOrLower(char alphabet)
{
  return (isLower(alphabet) ? toUpper(alphabet) : toLower(alphabet));
}

bool vowelsChecker(string Text, uint16_t pos)
{
  string strVowels{"aeiou"};
  uint16_t i = 0;

  for (i = 0; i < strVowels.length(); ++i) {
    if (Text[pos] == UpperOrLower(strVowels[i]) || Text[pos] == strVowels[i])
      return (true);
  }
  return (false);
}

uint16_t countVowels(string Text)
{
  uint16_t i = 0, count = 0;

  for (i = 0; i < Text.length(); i++) {
    if (vowelsChecker(Text, i))
      count++;
  }

  return (count);
}

void printVowelCount(string Text)
{
  cout<<"\nNumber of vowels is: "<<countVowels(Text)<<endl;
}

int main(void)
{
  string Text = readText("Enter a text to check:\n");
  printVowelCount(Text);
  return (0);
}
