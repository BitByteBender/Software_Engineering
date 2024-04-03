#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
  string str1 = "My name";

  str1.append(" is ");
  cout<<str1<<'\n';

  if (str1.at(10) == ' ') {
    str1.append("soufiane");
  }

  cout<<str1<<endl;

  uint16_t i = 0;

  for (i = 0; i < str1.length(); i++) {
    if (i == 11)
      str1[i] = 'S';
    
    if (i == (str1.length() - 1)) {
      str1.append(" topG");
      break;
    }
  }

  cout<<str1<<endl;
  
  return (0);
}
