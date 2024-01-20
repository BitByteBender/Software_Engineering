#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
  string str1 = "This is narly";

  cout<<"str1: "<<str1<<'\n';
  cout<<"length: "<<str1.length()<<'\n';

  string str2 = str1.substr(8, 4);

  cout<<"sub string: "<<str2<<'\n';
  cout<<"length: "<<str2.length()<<'\n';

  str2.push_back('y');
  str2.push_back('!');

  cout<<"using push_back: "<<str2<<'\n';
  cout<<"length: "<<str2.length()<<'\n';

  str2.pop_back();
  str2.pop_back();
  str2.pop_back();
  str2.pop_back();

  cout<<"using pop_back: "<<str2<<'\n';
  cout<<"length: "<<str2.length()<<'\n';
  return (0);
}
