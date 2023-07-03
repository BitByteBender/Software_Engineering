#include <iostream>

using std::cout;
using std::endl;

enum enColor{Red = 1, Green = 2, Blue = 3 };

int main()
{
  enColor Color;

  Color = enColor::Red;
  cout<<"Color is: "<<Color<<"\n";

  Color = enColor::Blue;
  cout<<"Color is: "<<Color<<"\n";

  Color = enColor::Green;
  cout<<"Color is: "<<Color<<endl;
  return 0;
}
