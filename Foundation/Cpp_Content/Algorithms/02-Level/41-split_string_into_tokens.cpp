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

uint16_t tokenizer(vector <string> &vWords, string Text)
{
  short pos = 0, tokens = 0;
  string word, DELIMITER = " ";
  
  while ((pos = Text.find(DELIMITER)) != std::string::npos) {
      word = Text.substr(0, pos);

      if (word != "") {
	tokens++;
	vWords.push_back(word);
      }

      Text.erase(0, pos + DELIMITER.length());
  }

  word = Text.substr(0, pos);
  
  if (word != "") {
    tokens++;
    vWords.push_back(word);
  }
  
  return (tokens);
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
  
  printTokens(vWords, tokenizer(vWords, Text));

  return (0);
}

