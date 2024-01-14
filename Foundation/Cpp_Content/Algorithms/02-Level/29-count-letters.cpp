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

inline bool uppercaseRange(char letter)
{
  return (letter >= 65 && letter <= 90);
}

inline bool lowercaseRange(char letter)
{
  return (letter >= 97 && letter <= 122);
}

uint16_t stringLength(string Text)
{
  return (Text.length());
}

uint16_t smallLetterCount(string Text)
{
  uint16_t i = 0, count = 0;

  for (i = 0; i < stringLength(Text); i++) {
    if (lowercaseRange(Text[i])) {
      ++count;
    }
  }
  return (count);
}

uint16_t capitalLetterCount(string Text)
{
  uint16_t i = 0, count = 0;

  for (i = 0; i < stringLength(Text); i++) {
    if (uppercaseRange(Text[i])) {
      ++count;
    }
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

  printResult(stringLength(Text), "String length: ");
  printResult(smallLetterCount(Text), "small letter count: ");
  printResult(capitalLetterCount(Text), "capital letter count: ");
  
  return (0);
}
