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

char upperToLowerCase(char letter)
{
  return (char(uint16_t(letter) + 32));
}

char lowerToUpperCase(char letter)
{
  return (char(uint16_t(letter) - 32));
}


bool upperCase(char letter)
{
  return (letter >= char(65) && letter <= char(90));
}

char flipCase(char letter)
{
  return (letter == upperCase(letter) ? upperToLowerCase(letter) : lowerToUpperCase(letter));
}

string replaceWord(string Text, string rWord, string newWord)
{
  string newStr;
  short pos = Text.find(rWord);

  while (pos != std::string::npos) {

    newStr += Text.substr(0, pos);
    newStr += newWord;

    Text = Text.erase(0, pos + rWord.length());
    pos = Text.find(rWord);
  }

  if (Text != "") {
    newStr += Text;
  }

  return (newStr);
}


string _replaceWord(string Text, string rWord, string newWord)
{
  string newStr;
  unsigned short i = 0, j = 0, len = rWord.length();
  
  for (i = 0; i < Text.length(); i++) {
    for (j = 0; j < rWord.length(); j++) {
      if ((Text[i + j] == rWord[j] || Text[i + j] == flipCase(rWord[j])) && (Text[len -j + i - 1] == rWord[len - j - 1] || Text[len -j + i - 1] == flipCase(rWord[len -j - 1]))) {
	newStr += newWord;
	i += len - 1;
	break;
      }
      
      if (Text[i + j] != rWord[j] || Text[len -j + i - 1] != rWord[len - j - 1]) {
	newStr += Text[i];
	break;
      }
    }
  }

  return (newStr);
}

void printText(string Text, string rWord, string newWord)
{
  cout<<"Replace with matched case:\n";
  cout<<replaceWord(Text, rWord, newWord)<<"\n\n";
  
  cout<<"Replace with unmatched case:\n";
  cout<<_replaceWord(Text, rWord, newWord)<<endl;
}

int main(void)
{
  string Text = readText("Enter a text:\n");
  string rWord = readText("You want to truncate: ");
  string newWord = readText("with: ");

  printText(Text, rWord, newWord);
  
  return (0);
}
