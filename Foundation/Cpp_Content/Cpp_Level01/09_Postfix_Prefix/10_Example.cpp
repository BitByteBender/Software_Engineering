#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short X{21}, Y{7}, Z{3};

  cout<<"X: "<<X<<"\n";
  cout<<"Y: "<<Y<<"\n";
  cout<<"Z: "<<Z<<"\n\n";

  X = X * 2 - --Y - (Z++ * 2) / 2 + X++;
  /*
    X = 42 - 6 - 3(+1) + 21(+1) = 54
    Y = 6
    Z = 4
  */
  cout<<"X: "<<X<<"\n";
  cout<<"Y: "<<Y<<"\n";
  cout<<"Z: "<<Z<<"\n\n";
  Y = X + ++Z + (Y * 2) - Y++ - (5 * ++X);
  /*
    X = 55
    Y = 54 + 5 + 12 - 6(+1) - 275 = -210
    Z = 5
  */
  cout<<"X: "<<X<<"\n";
  cout<<"Y: "<<Y<<"\n";
  cout<<"Z: "<<Z<<"\n\n";
  Z = ++Z + 5 + (Y++ * 2) / 2;
  /*
    X = 55
    Y = -209
    Z = 6 + 5 - 210(+1) = -199
  */
  cout<<"X: "<<X<<"\n";
  cout<<"Y: "<<Y<<"\n";
  cout<<"Z: "<<Z<<"\n\n";
  return 0;
}
