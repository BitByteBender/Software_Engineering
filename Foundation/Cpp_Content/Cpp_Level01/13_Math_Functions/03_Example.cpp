#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

int main()
{
  float X{1586.785f};
  float Y = X * 55.0f;

  cout<<Y<<"\n";
  cout<<sqrt(X) + sqrt(Y)<<"\n";
  cout<<round(X) + round(Y)<<"\n";
  cout<<round(sqrt(X)) + round(sqrt(Y))<<"\n";
  cout<<round(sqrt(X) + sqrt(Y))<<"\n";
  cout<<sqrt(round(X) + round(Y))<<"\n";
  cout<<round(sqrt(round(X) + round(Y)))<<endl;
  return 0;
}
