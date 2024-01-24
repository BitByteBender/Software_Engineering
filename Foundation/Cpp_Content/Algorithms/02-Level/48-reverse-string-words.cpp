#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

string readText(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin, Text);

  return (Text);
}

uint16_t countLength(string Text)
{
  string DELIMITER = " \n\t,/:;.", Word = "", arrWords[100];
  string isolator = "";
  uint16_t i = 0, j = 0, length = 0;
  
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
	arrWords[length] = Word;
	Word.clear();
	++length;
      }
      if (!isolator.empty()) {
	arrWords[length] = isolator;
	isolator.clear();
	++length;
      }
    }
  }

  if (!Word.empty()) {
    arrWords[length] = Word;
    Word.clear();
  }
  
  return (length);
}

void reverse(string Text, uint16_t length, string arrWords[])
{
  string DELIMITER = " \n\t,/:;.", Word = "";
  string isolator = "";
  uint16_t i = 0, j = 0;

  length = 0;
  
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
	arrWords[length] = Word;
	Word.clear();
	++length;
      }
      if (!isolator.empty()) {
	arrWords[length] = isolator;
	isolator.clear();
	++length;
      }
    }
  }

  if (!Word.empty()) {
    arrWords[length] = Word;
    Word.clear();
  }

  if (!isolator.empty()) {
    ++length;
    arrWords[length] = isolator;
    isolator.clear();
  }
}

void printReversed(string Text, string arrWords[])
{
  uint16_t i = 0;
  
  for (i = 0; i <= countLength(Text); i++) {
    cout<<arrWords[countLength(Text) - i];
  }
  cout<<endl;
}

int main(void)
{
  string Text = readText("enter a text:\n");
  uint16_t length = countLength(Text);
  string arrWords[length + 1];

  reverse(Text, length, arrWords);
  printReversed(Text, arrWords);
  
  return (0);
}
