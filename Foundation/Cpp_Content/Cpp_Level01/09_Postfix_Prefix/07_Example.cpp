#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short A{5}, B{0}, C{3};

  A = --B + C + ++C - A-- + A++ - ++A + A-- - --A + C++ + ++C;// 11 = -1 + 3 + 4 - 5(-1) + 4(+1) - 6 + 6(-1) - 4 + 4(+1) + 6
  /*
  A = 11
  B = -1
  C = 6
  */
  cout<<"A: "<<A<<"\nB: "<<B<<"\nC: "<<C<<"\n\n";
  
  C = A++ - --C + ++B; // 6 = 11(+1) - 5 + 0
  /*
    A = 12
    B = 0
    C = 6
  */
  cout<<"A: "<<A<<"\nB: "<<B<<"\nC: "<<C<<"\n\n";
  
  B = C++ - ++C + A++ + A - --A + B + ++B; //   = 6(+1) - 8 + 12(+1) + 13 - 12 + 0 + 1
  /*
  A = 12
  B = 12
  C = 8
  */
  cout<<"A: "<<A<<"\nB: "<<B<<"\nC: "<<C<<endl;
  
  return 0;
}
