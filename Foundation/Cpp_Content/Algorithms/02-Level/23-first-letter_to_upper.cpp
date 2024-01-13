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

char toUpper(char alphabet)
{
  return (char(uint16_t(alphabet) - 32));
}

bool isAlphabet(char letter)
{
  return (letter >= char(97) && letter <= char(122));
}

bool isLower(string Text, uint16_t pos)
{
  return (pos == 0 || (Text[pos - 1] == ' ' && isAlphabet(Text[pos])));
}

void printResult(string Text)
{
  uint16_t i = 0;

  for (i = 0; i < Text.length(); i++) {
    if (isLower(Text, i))
      cout<<toUpper(Text[i]);
    else
      cout<<Text[i];
  }
  cout<<endl;
}

int main(void)
{
  string Text = readText("Enter a text: ");
  printResult(Text);
  return (0);
}
