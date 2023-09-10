#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

int main()
{
  short A{9};

  cout<<"Square root of A is: "<<sqrt(A)<<"\n";//3
  cout<<"Square root of 128 is: "<<sqrt(121)<<"\n";//11

  A = (A++ * 2) + 15 + ++A;//44
  cout<<"Square root of "<<A<<" is: "<<sqrt(A)<<"\n";

  A = A / 2 + ++A - 3 + --A + 5;//113
  cout<<"Square root of "<<A<<" is: "<<sqrt(A)<<endl;
  return 0;
}
