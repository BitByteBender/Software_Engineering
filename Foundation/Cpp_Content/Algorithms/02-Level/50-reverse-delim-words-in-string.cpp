#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

string readText(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin, Text);

  return (Text);
}

vector <string> reverse(string Text)
{
  vector <string> vWords;
  string DELIMITER = " \n\t,/:;", Word = "";
  string isolator = "";
  uint16_t i = 0, j = 0;

  vWords.push_back("\0");
  
  for (i = 0; i < Text.length(); i++) {
    for (j = 0; j < DELIMITER.length(); j++) {
      if (Text[i] == DELIMITER[j]) {
	isolator += DELIMITER[j];
      }
    }
    if (isolator == "") {
      Word += Text.at(i);
    } else {
      if (!Word.empty()) {
        vWords.push_back(Word);
	Word.clear();
      }
      if (!isolator.empty()) {
        vWords.push_back(isolator);
	isolator.clear();
      }
    }
  }

  if (!Word.empty()) {
    vWords.push_back(Word);
    Word.clear();
  }

  return (vWords);
}

void printReversed(vector <string> &vWords)
{
  vector <string>::iterator iter;

  for (iter = vWords.end(); iter != vWords.begin(); iter--) {
    cout<<*iter;
  }
  cout<<endl;
}

int main(void)
{
  string Text = readText("enter a text:\n");
  vector <string> vWords;

  vWords = reverse(Text);
  printReversed(vWords);
  
  return (0);
}
