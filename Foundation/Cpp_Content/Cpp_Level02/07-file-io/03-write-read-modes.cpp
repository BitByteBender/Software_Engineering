#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ios;
using std::to_string;

void writeToFile()
{
  uint16_t i = 0;
  fstream File;
  
  File.open("tests/test01", ios::out);

  if (File.is_open()) {
    for (i = 0; i <= 10; i++) {
      File<<i<<" * "<<(i + 1)<<'\n'; 
    }
    File.close();
  }
}

void fileReader(string Filename)
{
  fstream File;
  File.open(Filename, ios::in);

  if (File.is_open()) {
    string line;
    
    while (getline(File, line)) {
      cout<<line<<'\n';
    }
    File.close();
  }
}

int main(void)
{
  writeToFile();
  fileReader("tests/test01");
  return (0);
}

