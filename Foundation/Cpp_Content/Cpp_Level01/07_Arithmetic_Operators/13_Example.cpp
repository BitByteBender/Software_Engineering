#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

int main()
{
  /*
    t = (a+b+c) / 2;
    AreaOfCircle(Described around an arbitrary triangle) =
    = PI * pow(((a*b*c) /(4 * sqrt(t *(t-a)*(t-b)*(t-c)))), 2)
  */
  unsigned short a{5}, b{6}, c{7};
  const float PI{3.14f};
  unsigned short t = (a + b + c) / 2;
  
  float AreaOfCircle = PI * pow(((a*b*c) /(4.0f * sqrt(t * (t-a)*(t-b)*(t-c)))), 2);
  
  cout<<"AreaOfCircle: "<<AreaOfCircle<<endl;
  return 0;
}
