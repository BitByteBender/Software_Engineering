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

string joinWords(string arr[], uint16_t &length, string DELIMITER)
{
  uint16_t i = 0;
  string Word;
  
  for (; i <= (length - 1); i++) {
    Word.append(arr[i] + DELIMITER);
  }

  return (Word.substr(0, Word.length() - DELIMITER.length()));
}

void printText(string Text)
{
  cout<<Text<<endl;
}

int main(void)
{
  vector <string> vWords = {"Pistachio Green", "Scarlet Red", "Black Piano"};
  uint16_t length = 4;
  string arr[length] = {"V1", "V2", "V3", "V4"};
  
  string str = joinWords(vWords, " | ");
  string str2 = joinWords(arr, length, ", ");
  
  printText(str);
  printText(str2);
  
  return (0);
}
