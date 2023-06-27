#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short A=150;
  short B= --A;//A will decrease by 1 then B will take the value of A.

  cout<<"B = "<<B<<"\n";
  cout<<"A = "<<A<<"\n";

  short C = B--;//C will take the value of B then B will decrease by 1.

  cout<<"C = "<<C<<"\n";
  cout<<"B = "<<B<<endl;
  return 0;
}
