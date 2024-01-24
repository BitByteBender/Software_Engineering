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

vector <string> splitWords(string Text)
{
  vector <string> vWords;
  string DELIMITER = " \n\t,/:;", Word = "";
  uint16_t i = 0, j = 0, counter = 0;
  
  for (i = 0; i < Text.length(); i++) {
    
    for (j = 0; j < DELIMITER.length(); j++) {
      
      if (Text[i] == DELIMITER[j]) {
	counter = j;
	break;
      }
      
    }
    
    if (DELIMITER[counter] != Text[i])
      Word += Text.at(i);
    else {
      if (!Word.empty()) {
	vWords.push_back(Word);
	Word.clear();
      }
    }
    
  }

  if (!Word.empty()) {
    vWords.push_back(Word);
    Word.clear();
  }

  return (vWords);
}

vector <string> splitDelims(string Text)
{
  vector <string> vDelims;
  string DELIMITER = " \n\t,/:;", Delim = "";
  uint16_t i = 0, j = 0, counter = 0;
  
  for (i = 0; i < Text.length(); i++) {
    
    for (j = 0; j < DELIMITER.length(); j++) {
      
      if (Text[i] == DELIMITER[j]) {
	counter = j;
	break;
      }
      
    }
    
    if (DELIMITER[counter] == Text[i])
      Delim += Text.at(i);
    else {
      if (!Delim.empty()) {
	vDelims.push_back(Delim);
	Delim.clear();
      }
    }
    
  }

  if (!Delim.empty()) {
    vDelims.push_back(Delim);
    Delim.clear();
  }
  
  return (vDelims);
}

string storeReversed(vector<string> &vWords, vector <string> &vDelims)
{
  vector <string>::iterator iter = vWords.end(), iter1 = vDelims.begin();
  string str = "";
  
  while (iter != vWords.begin() || iter1 != vDelims.end())
  {
    iter--;
    str += *iter;

    if (iter1 != vDelims.end()) {
      str += *iter1;
      iter1++;
    }
  }

  return (str);
}

void printReversed(string rStr)
{
  cout<<rStr;
  cout<<endl;
}

int main(void)
{
  string Text = readText("enter a text:\n"), rStr = "";
  vector <string> vWords;
  vector <string> vDelims;
  
  vWords = splitWords(Text);
  vDelims = splitDelims(Text);
  rStr = storeReversed(vWords, vDelims);
  printReversed(rStr);
  cout<<endl;
  return (0);
}
