#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

int main()
{
  short X{15}, Y{3};
  cout<<pow(X, 2)<<"\n";
  cout<<pow(X, Y)<<"\n";
  cout<<pow(Y, X)<<"\n";
  cout<<pow(Y, 3)<<"\n";
  cout<<pow(3, Y)<<endl;
  return 0;
}
