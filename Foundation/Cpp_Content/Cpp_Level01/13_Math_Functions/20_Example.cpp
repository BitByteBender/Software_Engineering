#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

int main()
{
  short T{52};

  cout<<"Square root of T is: "<<sqrt(T)<<"\n";
  cout<<"Rounding Sqrt(T): "<<round(sqrt(T))<<"\n\n";

  T = 7 + --T + 7 + ++T * 3 * 2 + T++ - 3 - T--;// 65 + 312 + 52(+1) - 3 - 53(-1) = 373
  cout<<"Square root of T is: "<<sqrt(T)<<"\n";
  cout<<"Flooring sqrt("<<T<<"): "<<floor(sqrt(T))<<"\n";
  cout<<"Ceiling sqrt("<<T<<"): "<<ceil(sqrt(T))<<endl;
  return 0;
}
