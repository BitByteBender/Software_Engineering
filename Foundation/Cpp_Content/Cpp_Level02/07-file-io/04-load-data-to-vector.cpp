#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::fstream;
using std::vector;
using std::cout;
using std::endl;
using std::string;

void writeToFile(string Filename)
{
  fstream File;

  File.open(Filename, std::ios::out);

  if (File.is_open()) {
    uint16_t i = 0;
    
    for (i = 0; i <= 5; i++) {
      File<<"Test "<<(i + 1)<<'\n';
    }
    File.close();
  }
}

vector <string> dataLoader(string Filename)
{
  fstream File;
  vector <string> vLines;

  File.open(Filename, std::ios::in);

  if (File.is_open()) {
    string line;

    while (getline(File, line)) {
      vLines.push_back(line);
    }

    File.close();
  }

  return (vLines);
}

void printDataFromVector(vector <string> &vLines)
{
  vector <string>::iterator iter;

  for (iter = vLines.begin(); iter != vLines.end(); iter++) {
    cout<<(*iter)<<'\n'; 
  }
  cout<<endl;
}

int main(void)
{
  string Filename = "tests/test02";
  vector <string> vLines;
  
  writeToFile(Filename);
  vLines = dataLoader(Filename);

  printDataFromVector(vLines);
  return (0);
}
