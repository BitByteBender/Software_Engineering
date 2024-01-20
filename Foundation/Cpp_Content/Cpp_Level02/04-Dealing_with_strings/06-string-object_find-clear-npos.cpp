#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
  string str1 = "My currently studying at Holberton";

  cout<<"str1: "<<str1<<'\n';
  cout<<"length: "<<str1.length()<<'\n';

  
  string str2 = "School";

  str1.append(' ' + str2);

  cout<<"str1: "<<str1<<'\n';
  cout<<"length: "<<str1.length()<<'\n';

  if (str1.find("Holberton") == str1.npos) {
    cout<<"Holberton not found";
  } else {
    cout<<"Holberton is found at pos[";
    cout<<str1.find("Holberton")<<"]["<<str1.find("n ")<<"].\n";
    cout<<"at pos 25->"<<str1.at(str1.find("Holberton"))<<'\n'
	<<"at pos 33->"<<str1.at(str1.find("n "))<<'\n';
  }

  str1.clear();
  
  cout<<"str1(used clear method): "<<str1<<'\n';
  cout<<"length: "<<str1.length()<<'\n';

  return (0);
}
