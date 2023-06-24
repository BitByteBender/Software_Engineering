#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Number{0};
  cout<<"Enter a number: ";
  cin>>Number;

  
  cout<<"Number to the power of 2: "<<Number * Number<<"\n";
  cout<<"Number to the power of 3: "<<Number * Number * Number<<"\n";
  cout<<"Number to the power of 4: "<<Number * Number * Number * Number<<endl;
  return 0;
}
