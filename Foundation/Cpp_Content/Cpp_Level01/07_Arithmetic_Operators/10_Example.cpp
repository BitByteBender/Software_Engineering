#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

int main()
{
  //Area Of A Circle inscribed in a square = PI * pow((Square/2), 2)
  const float PI{3.14f};
  unsigned short Square{10};
  float AreaOfCircle = PI * pow((Square/2), 2);
  cout<<"Area of a circle inscribed in a Square: "<<AreaOfCircle<<endl;
  return 0;
}
