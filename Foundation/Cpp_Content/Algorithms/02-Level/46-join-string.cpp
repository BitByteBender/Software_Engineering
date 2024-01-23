#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

string joinWords(vector <string> &vWords, string DELIMITER)
{
  string sWord;
  vector <string>::iterator iter;

  for (iter = vWords.begin(); iter != vWords.end(); iter++) {
    if (*iter == vWords.back()) {
      sWord.append(*iter);
    } else {
      sWord.append(*iter);
      sWord.append(DELIMITER);
    }
  }

  return (sWord);
}

void printText(string Text)
{
  cout<<Text<<endl;
}

int main(void)
{
  vector <string> vWords = {"Gamma", "Theta", "Delta"};

  string str = joinWords(vWords, " ");

  printText(str);
  
  return (0);
}
