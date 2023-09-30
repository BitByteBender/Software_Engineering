#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string ArrA[3];
  cout<<"Enter a name: ";
  getline(cin, ArrA[0]);

  cout<<"Enter a name: ";
  getline(cin, ArrA[1]);

  cout<<"Enter a name: ";
  getline(cin, ArrA[2]);

  cout<<"Array of names: "<<ArrA[0]<<", "<<ArrA[1] + ", " + ArrA[2]<<endl;
  return 0;
}

