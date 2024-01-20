#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
  string str1 = "I love programming!!";

  cout<<"str1: "<<str1<<'\n';
  cout<<"length: "<<str1.length()<<'\n';

  string str2 = str1.substr(7, 11);

  cout<<"sub string: "<<str2<<'\n';
  cout<<"length: "<<str2.length()<<'\n';

  return (0);
}
