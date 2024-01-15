#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
  string str1 = "My name is soufiane";
  
  cout<<str1.at(9)<<str1.at(12)<<str1.at(13)<<str1.at(14)<<'\n';
  cout<<str1.at(0)<<' '<<str1.at(1)<<'\n';

  uint16_t i = 0;
  
  for (i = 0; i < str1.length(); ++i) {
    cout<<str1.at(i);
  }

  cout<<'\n';
  
  if (str1.at(1) == 'y') {
    str1.at(1) = 'a';
  }

  for (i = 0; i < str1.length(); ++i) {
    if (i == (str1.length() - 1))
      str1.at(str1.length() - 1) = '.';
    cout<<str1.at(i);
  }
  
  cout<<endl;
  return (0);
}
