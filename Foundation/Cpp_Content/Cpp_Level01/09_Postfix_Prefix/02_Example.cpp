#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short A=150;
  short B= A++;//B will take the A value before the increase, then A will increase by 1.

  cout<<"B = "<<B<<"\n";
  cout<<"A = "<<A<<endl;
  return 0;
}
