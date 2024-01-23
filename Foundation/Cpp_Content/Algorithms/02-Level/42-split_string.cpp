#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

string readText(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin, Text);

  return (Text);
}

vector <string> splitString(string Text, string DELIMITER)
{
  vector <string> vWords;
  
  short pos = 0;
  string word;
  
  while ((pos = Text.find(DELIMITER)) != std::string::npos) {
      word = Text.substr(0, pos);

      if (word != "") {
	vWords.push_back(word);
      }

      Text.erase(0, pos + DELIMITER.length());
  }

  if (Text != "") {
    vWords.push_back(Text);
  }
  
  return (vWords);
}

void printTokens(vector <string> &vWords, short tokens)
{

  cout<<"tokens = "<<tokens<<'\n';
  
  for (string &Word : vWords) {
    cout<<Word<<'\n';
  }
  cout<<endl;
}

int main(void)
{
  string Text = readText("Enter a text: ");

  vector <string> vWords;
  
  vWords = splitString(Text, "/");
  printTokens(vWords, vWords.size());

  return (0);
}

