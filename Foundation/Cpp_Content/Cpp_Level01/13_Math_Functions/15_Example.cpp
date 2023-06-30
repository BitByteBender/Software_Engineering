#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
  unsigned short Num{0}, Exponent{0};

  cout<<"Enter a number: ";
  cin>>Num;

  cout<<"Enter the exponent: ";
  cin>>Exponent;

  cout<<pow(Num, Exponent)<<endl;
  return 0;
}
