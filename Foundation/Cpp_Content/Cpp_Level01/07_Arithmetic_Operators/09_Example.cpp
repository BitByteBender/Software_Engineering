#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

int main()
{
  //Area of Circle Through Diameter = PI * pow((Diameter/2), 2)
  const float PI{3.14f};
  short Diameter{35};

  float AreaOfCircleThroughDiameter = PI * pow((Diameter/2), 2);
  cout<<"Area of a circle through Diameter: "<<AreaOfCircleThroughDiameter<<endl;
  return 0;
}
