#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum enLetterCase{Upper = 1, Lower = 2, All = 3};

string readText()
{
  string Text{"empty"};

  cout<<"Enter a text: ";
  getline(cin, Text);

  return (Text);
}

inline bool isUpper(char letter)
{
  return (letter >= 65 && letter <= 90);
}

inline bool isLower(char letter)
{
  return (letter >= 97 && letter <= 122);
}

uint16_t stringLength(string Text)
{
  return (Text.length());
}

uint16_t countLetters(string Text, enLetterCase letterCase=enLetterCase::All)
{
  uint16_t i = 0, count = 0;

  if (letterCase == enLetterCase::All) {
    return (Text.length());
  }
  
  for (i = 0; i < stringLength(Text); i++) {
    if (letterCase == enLetterCase::Lower && isLower(Text[i]))
      ++count;

    if (letterCase == enLetterCase::Upper && isUpper(Text[i]))
      ++count;
  }
  
  return (count);
}

void printResult(uint16_t Number, const char *Msg)
{
  cout<<Msg;
  cout<<Number;
  cout<<endl;
}

int main(void)
{
  string Text = readText();

  printResult(countLetters(Text), "String length: ");
  printResult(countLetters(Text, enLetterCase::Lower), "small letter count: ");
  printResult(countLetters(Text, enLetterCase::Upper), "capital letter count: ");
  
  return (0);
}
