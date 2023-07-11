#include <iostream>

using std::cout;
using std::endl;


int main()
{
  short FirstNum{0}, SecondNum{0}, ThirdNum{0};
  double NumInDouble{25.75};

  FirstNum = NumInDouble; // Implicit Conversion from double to short
  cout<<FirstNum<<"\n";

  SecondNum = (short)NumInDouble; //Explicit conversion in C-style
  cout<<SecondNum<<"\n";

  ThirdNum = short(NumInDouble);// Explicit conversion using the short function
  cout<<ThirdNum<<endl;
  
  return 0;
}
