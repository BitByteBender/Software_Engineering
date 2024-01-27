#include <iostream>
#include <string>

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

bool lowerCase(uint16_t letter)
{
  return (letter >= 97 && letter <= 122);
}
  
bool upperCase(uint16_t letter)
{
  return (letter >= 65 && letter <= 90);
}
  
bool checkLetter(char letter)
{
  return (letter == upperCase(letter) || letter == lowerCase(letter));
}

string removePunct(string Text)
{
  string puncts = ",;,:!?.\"'", strHolder;
  uint16_t i = 0, j = 0;
  
  for (i = 0; i < Text.length(); i++) {
    if (Text[i] == checkLetter(Text[i]) || Text[i] == ' ') {
      strHolder += Text[i];
      continue;
    }

    for (j = 0; j < puncts.length(); j++) {
      if (Text[i] == puncts[j])
	break;
	
      if (Text[i] != puncts[j] && j == puncts.length() - 1)
	strHolder += Text[i];
    }
  }

  Text.clear();
  Text = strHolder;
  
  return (Text);
}

void printModifiedString(string newText)
{
  cout<<newText<<endl;
}

int main(void)
{
  string Text = readText("Enter a text:\n");

  printModifiedString(removePunct(Text));
  
  return (0);
}
