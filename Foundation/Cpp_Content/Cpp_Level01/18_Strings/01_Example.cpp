#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string Fullname{"Empty"};

  cout<<"Enter your fullname: ";
  getline(cin, Fullname);

  cout<<"Fullname: "<<Fullname<<"\n";
  return 0;
}
