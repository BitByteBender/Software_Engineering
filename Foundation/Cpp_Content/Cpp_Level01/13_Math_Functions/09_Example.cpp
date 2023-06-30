#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Diameter{0};

  cout<<"Enter the circle Diameter: ";
  cin>>Diameter;

  const float PI{3.14f};
  float CircleArea = PI * pow((Diameter / 2), 2);
  cout<<"Circle Area through Diameter: "<<CircleArea<<"\n";
  cout<<"Using the ceiling function: "<<ceil(CircleArea)<<endl;
  return 0;
}
