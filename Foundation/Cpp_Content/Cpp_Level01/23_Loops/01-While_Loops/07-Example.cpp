#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short Number{0}, Sum{0};

  cout<<"Enter a number: ";
  cin>>Number;

  while (Number != -99) {
    Sum = Sum + Number;
    cin>>Number;
  }
  
 cout<<Sum<<endl;
  return 0;
}
