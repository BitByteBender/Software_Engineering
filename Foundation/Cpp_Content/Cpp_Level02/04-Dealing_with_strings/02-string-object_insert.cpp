#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
  string str1 = "My name is fiane";

  cout<<"str1: "<<str1<<'\n';
  cout<<"length: "<<str1.length()<<'\n';

  str1.insert(11, "Sou");

  cout<<"new string: "<<str1<<'\n';
  cout<<"length: "<<str1.length()<<'\n';

  return (0);
}
