#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short A{0}, B{5};

  cout<<"A: "<<A<<"\nB: "<<B<<"\n\n";

  A = B++ + 1 + (++A * 2) + A-- + 8;
  /*
  B = 5(+1) => 6
  A = 5 + 1 + 2 + 1 + 8 => 17
  */
  cout<<"A: "<<A<<"\nB: "<<B<<"\n\n";

  B = (A * 2) + ++B + 5;
  /*
  A = 17
  B = 34 + 7 + 5 => 46
  */
  cout<<"A: "<<A<<"\nB: "<<B<<"\n\n";

  A = 3, B = 6;

  B = A++ + 2 + (++A * 3) + 6 + A--;
  /*
  B = 3(+1) + 2 + 15 + 6 + 5(-1) = 31
  A = 4
  */
  cout<<"A: "<<A<<"\nB: "<<B<<"\n\n"; 
  return 0;
}
