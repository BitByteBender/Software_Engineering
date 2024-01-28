#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::fstream;
using std::ios;

vector <string> readText(uint16_t &length)
{
  vector <string> vData;
  string Text;
  
  cout<<"Enter Text N°1: ";
  
  do {
    if (length > 0) {
      cout<<"Enter Text N°"<<(length + 1)<<": ";
    }
    getline(cin, Text);
    vData.push_back(Text);
    length++;
  } while (length < 5);
  
  return (vData);
}

void writeToFile(string Filename, vector <string> &vData)
{
  fstream MyFile;

  MyFile.open(Filename, ios::out | ios::app);

  if (MyFile.is_open()) {
    for (const string &Data : vData) {
      MyFile<<Data<<'\n';
    }
    MyFile.close();
  }
}

void readFile(string Filename)
{
  fstream MyFile;

  MyFile.open(Filename, ios::in);

  if (MyFile.is_open()) {
    string line;

    while (getline(MyFile, line)) {
      cout<<line<<'\n';
    }
    MyFile.close();
  }
}

int main(void)
{
  vector <string> vData;
  uint16_t length = 0;
  string Filename = "tests/test03";
  
  vData = readText(length);
  writeToFile(Filename, vData);
  readFile(Filename);
  
  return (0);
}
