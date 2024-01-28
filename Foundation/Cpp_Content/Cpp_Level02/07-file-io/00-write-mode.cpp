#include <iostream>
#include <fstream>

using std::endl;
using std::fstream;
using std::ios;

int main(void)
{
  fstream File;

  File.open("test00", ios::out);

  if (File.is_open()) {
    File<<"This 1st line\n";
    File<<"This 2nd line";
    File<<"\nThis is 3rd line\n";
    File<<"This is 4th line"<<endl;
    
    File.close();
  }
  return (0);
}
