#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

int main()
{
  float X{75.0f};
  X = X * 15.13f;
  cout<<X<<"\n";
  cout<<round(X)<<"\n";
  cout<<round(sqrt(X))<<"\n";
  cout<<round(100.55)<<"\n";//round up it is >= .5 (Result: 101)
  cout<<round(1573.35)<<endl;//round down it is <= .5 (Result: 1573)
  return 0;
}
