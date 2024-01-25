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

bool checkDelimiter(char Letter)
{
  return (Letter == ' ' || Letter == 'i' || Letter == ',' || Letter == '.');
}

string replaceText(string Text, string rWord, string newWord)
{
  unsigned short i = 0, j = 0;
  string newStr;
  
  newStr += Text[0];

  for (i = 1; i < Text.length(); i++) {

    if (Text[i - 1] != ' ' || !checkDelimiter(Text[i + rWord.length()])) {
      newStr += Text.at(i);
      continue;
    }
    
    for (j = 0; j < rWord.length(); j++) {
      
      if (Text[i + j] != rWord[j] || Text[rWord.length() - j + i - 1] != rWord[rWord.length() - j -1]) {
	newStr += Text.at(i);
	break;
      }

      if (Text[i + j] == rWord[j] && Text[rWord.length() - j + i - 1] == rWord[rWord.length() - j -1]) {
	newStr += newWord;
	i += rWord.length() - 1;
	break;
      }
    }
  }

  return (newStr);
}

void printText(string Text)
{
  cout<<Text<<endl;
}

int main(void)
{
  string Text = readText("Enter a text:\n");
  string rWord = readText("You want to truncate: ");
  string newWord = readText("with: ");
  
  printText(replaceText(Text, rWord, newWord));
  
  return (0);
}
