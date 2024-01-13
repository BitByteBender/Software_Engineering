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

bool getLetters(string Text, uint16_t number)
{
  return ((Text[number - 1] == ' ' && Text[number] != ' ') || number == 0);
}

void printLetters(string Text)
{
  uint16_t i = 0;

  for (i = 0; i < Text.length(); i++) {
    if (getLetters(Text, i)) {
      cout<<Text[i]<<'\n'; 
    }
  }
  cout<<endl;
}

int main(void)
{
  string Txt = readText("Enter a long text: ");
  printLetters(Txt);
  return 0;
}
