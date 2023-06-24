#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

int main()
{
  //CircleArea(Inscribed in an isosceles triangle) = PI * pow((base/2), 2) * ((2 * length - base) / (2 * length + base)

  unsigned short Base{10}, Length{20};
  const float PI{3.14f};

  float CircleArea = PI * pow((Base/2), 2) * ((2.0f * Length - Base) / (2.0f * Length + Base));
  cout<<"CircleArea: "<<CircleArea<<endl;
  return 0;
}
