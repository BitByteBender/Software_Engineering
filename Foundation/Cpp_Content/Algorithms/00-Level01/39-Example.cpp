#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadNumber(string Message)
{
  short Num{0};
  
  cout<<Message;
  cin>>Num;
  
  return Num;
}

void _PrintExponent(short Number)
{
  short Exponent = Number;
  for (int i = 0; i < 3; i++) {
    Exponent = Exponent * Number;
    cout<<Exponent<<"\n";
  }
  cout<<endl;
}

int main()
{
  short Number{0};

  Number = ReadNumber("Enter a number: ");
  _PrintExponent(Number);
  
  return 0;
}
