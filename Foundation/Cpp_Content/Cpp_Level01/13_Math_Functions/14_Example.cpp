#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
  unsigned short Number{0};

  cout<<"Enter a number: ";
  cin>>Number;

  cout<<pow(Number, 2)<<"\n";
  cout<<pow(Number, 3)<<"\n";
  cout<<pow(Number, 4)<<endl;
  return 0;
}
