#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

int main()
{
  /*
    Circumference = PI * Diameter => Circumference = PI * 2 * r
    Radius = Circumference / (2 * PI)
    AreaOfCircle = PI * pow(Radius, 2)
    AreaOfCircleAlongCircumference = PI * pow((Circumference/(2*PI)), 2)
  */
  
  unsigned short Circumference{20};
  const float PI{3.14f};
  float AreaOfCircleAlongCircumference = PI * pow((Circumference/(2 * PI)), 2);

  cout<<"AreaOfCircleAlongCircumference: "<<AreaOfCircleAlongCircumference<<endl;
  return 0;
}
