#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
  short Diameter{0};
  const float PI{3.14f};
  float CircleArea{0};
  
  cout<<"What's the Diameter?\n ";
  cin>>Diameter;

  CircleArea = PI * pow((Diameter / 2), 2);

  cout<<"CircleArea through Diameter: "<<CircleArea<<endl;
  return 0;
}
