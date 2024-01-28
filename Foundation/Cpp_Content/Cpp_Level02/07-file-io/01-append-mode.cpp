#include <iostream>
#include <fstream>

using std::fstream;
using std::ios;
using std::endl;

int main(void)
{
  fstream File;

  File.open("tests/test00", ios::out | ios::app);

  if (File.is_open()) {
    File<<"This is the 5th line";
    File<<"\nThis is the 6th line\n";
    File<<"(end)"<<endl;
    File.close();
  }
  
  return (0);
}
