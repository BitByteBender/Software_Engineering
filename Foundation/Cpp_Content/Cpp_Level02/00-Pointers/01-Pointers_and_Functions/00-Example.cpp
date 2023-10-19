#include <iostream>

using std::cout;
using std::endl;

short Calculate(short* Num)
{
  return (*Num * 2);
}

int main()
{
  short Number{5};
  short* ptr{nullptr};

  //pointing to Number's(Store the address of varNumber)
  ptr = &Number;

  cout<<Calculate(ptr)<<"\n";

  //dereferencing
  *ptr = 15;
  cout<<Calculate(ptr)<<"\n";
  return 0;
}
