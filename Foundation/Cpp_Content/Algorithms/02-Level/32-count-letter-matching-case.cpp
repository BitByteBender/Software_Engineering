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

inline char toUpper(char letter)
{
  return (char(uint16_t(letter) - 32));
}

inline bool isUpper(char letter)
{
  return (letter >= 65 && letter <= 90);
}

inline char lowerOrUpper(char letter)
{
  return (isUpper(letter) ? toLower(letter) : toUpper(letter));
}

uint16_t countLetterInString(string Text, char Letter)
{
  uint16_t i = 0, count = 0;

  for (i = 0; i < Text.length(); i++) {
    if (Text[i] == Letter)
      count++;
  }

  return (count);
}

uint16_t countSimilarLettersInString(string Text, char Letter)
{
  uint16_t i = 0, count = 0;

  for (i = 0; i < Text.length(); i++) {
    if (Text[i] == lowerOrUpper(Letter) || Text[i] == Letter) {
      count++;
    }
  }

  return (count);
}

void printResult(string Text, char Letter, const char *Msg)
{
  printf("Letter '%c'%s%d", Letter, Msg, countLetterInString(Text, Letter));
  cout<<'\n';
  printf("Letter '%c' or '%c'%s%d", Letter, lowerOrUpper(Letter), Msg, countSimilarLettersInString(Text, Letter));
  cout<<endl;
}

int main(void)
{
  string Text = readText();
  char Letter = readChar("Enter a character that you want to check: ");

  printResult(Text, Letter, " count = ");
  return (0);
}
