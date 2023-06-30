#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
  unsigned short Radius{0};

  cout<<"Enter the radius: ";
  cin>>Radius;

  const float PI{3.14f};
  float CircleArea =  PI * pow(Radius, 2);
  cout<<"Area of a circle: "<<CircleArea<<endl;
  return 0;
}
