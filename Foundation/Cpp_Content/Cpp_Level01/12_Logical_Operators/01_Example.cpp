#include <iostream>

using std::cout;
using std::endl;

int main()
{
  bool X{false}, Y{true};

  cout<<(X && Y)<<"\n";//false(they both need to be true to become true)
  cout<<(X || Y)<<"\n";//true(one of them needs to be true)
  cout<<!(X && Y)<<endl;//true(Not false)
  return 0;
}
