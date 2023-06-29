#include <iostream>

using std::cout;
using std::endl;


int main()
{
  short X{15}, Y{88};

  cout<<(X == Y)<<"\n";//False
  cout<<(X != Y)<<"\n";//True
  cout<<(X > Y)<<"\n";//False
  cout<<(X < Y)<<"\n";//True
  cout<<(X >= Y)<<"\n";//False
  cout<<(X <= Y)<<endl;//True
  return 0;
}
