#include <iostream>
#include <fstream>
#include <string>

using std::fstream;
using std::ios;
using std::string;
using std::cout;
using std::endl;

int main(void)
{
  fstream File;
  string line;
  
  File.open("tests/test00", ios::in);

  if (File.is_open()) {

    while (getline(File, line)) {
      if (!line.empty()) {
	cout<<line<<'\n';
      }
    }
    
    File.close();
  }

  cout<<endl;
  return (0);
}
