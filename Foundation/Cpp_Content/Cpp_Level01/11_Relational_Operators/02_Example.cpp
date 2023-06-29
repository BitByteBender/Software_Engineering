#include <iostream>

using std::cout;
using std::endl;


int main()
{
  short X{35}, Y{5};

  cout<<(X == Y)<<"\n";//false
  cout<<(X != Y)<<"\n";//true
  cout<<(X > Y)<<"\n";//true
  cout<<(X < Y)<<"\n";//false
  cout<<(X >= Y)<<"\n";//true
  cout<<(X <= Y)<<endl;//false
  return 0;
}
