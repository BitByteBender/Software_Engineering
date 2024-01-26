#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

string readText(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin, Text);

  return (Text);
}

char toLower(char letter)
{
  return (char(uint16_t(letter) + 32));
}

bool isLower(uint16_t ASCII_Letter)
{
  return (ASCII_Letter >= 97 && ASCII_Letter <= 122);
}

char caseChecker(char letter)
{
  return (isLower(letter) ? letter : toLower(letter));
}

string lowerString(string Text)
{
  uint16_t i = 0;
  
  while (Text[i] != '\0') {
    if (Text[i] == ' ') {
      i++;
      continue;
    }
    Text[i] = caseChecker(Text[i]);
    i++;
  }

  return (Text);
}

vector <string> splitString(string Text, string Delim)
{
  vector <string> vWords;
  short pos = 0;

  Delim = " ";
  
  while ((pos = Text.find(Delim)) != string::npos) {
    vWords.push_back(Text.substr(0, pos));

    Text.erase(0, pos + Delim.length());
  }

  if (!Text.empty()) {
    vWords.push_back(Text);
    Text.clear();
  }

  return (vWords);
}

string joinString(vector <string> &vWords, string Delim)
{
  vector <string>::iterator iter;
  string str = "";
  
  for (iter = vWords.begin(); iter != vWords.end(); iter++) {
    str += *iter + Delim;
  }

  str.erase(str.length() - Delim.length());
  
  return (str);
}

string replaceString(string text, string replaceWord, string newWord, bool isMatching=true)
{
  vector <string> vSplit = splitString(text, " ");

  for (string &str : vSplit) {
    if (isMatching) {
      if (str == replaceWord) {
	str = newWord;
      }
    } else {
      if (lowerString(str) == lowerString(replaceWord)) {
	str = newWord;
      }
    }
  }

  return (joinString(vSplit, " "));
}

void printCases(string newText, const char *Msg)
{
  cout<<Msg;
  cout<<newText<<endl;
}

int main(void)
{
  string Text = readText("Enter a text:\n");
  string replaceWord = readText("Choose a word from text you want to truncate: ");
  string newWord = readText("replacement word: ");

  /**
   * Testing
   * vector <string> vWords;
   *
   * cout<<lowerString(Text)<<endl;
   * vWords = splitString(lowerString(Text), " ");
   *
   * for (const string &str : vWords) {
   * cout<<str<<'\n';
   * }
   * cout<<endl;
   *
   * cout<<joinString(vWords, " ")<<endl;
  */
  
  printCases(replaceString(Text, replaceWord, newWord, false), "\nUnmatched replacement:\n");
  printCases(replaceString(Text, replaceWord, newWord, true), "\nMatched replacement:\n");
  return (0);
}
