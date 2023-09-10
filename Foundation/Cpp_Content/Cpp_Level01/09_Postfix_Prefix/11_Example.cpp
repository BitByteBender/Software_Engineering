#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short Y{5}, W{7};

  cout<<"Y: "<<Y<<"\nW: "<<W<<"\n\n";

  Y = ++W + 2 - Y-- + W++ + 7 + --W + 2 + (Y * 2) + (Y++ * 2);
  /*
    Y = 48
    W = 8
    Overall = 8 + 2 - 5(-1) + 8(+1) + 7 + 8 + 2 + 8 + 10 = 48
  */
  cout<<"Y: "<<Y<<"\nW: "<<W<<"\n\n";
  
  W = ++Y - W++ + (++W * 2) - (--Y * 2) - Y;
  /*
    Y = 48
    W = -83
    Overall = 49 - 8(+1) + 20 - 96 - 48 = -83
  */
  cout<<"Y: "<<Y<<"\nW: "<<W<<"\n\n";

  
  return 0;
}
