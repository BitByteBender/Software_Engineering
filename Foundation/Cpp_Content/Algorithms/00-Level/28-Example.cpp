#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

short ReadNumbers()
{
  short Diameter{0};
  
  cout<<"Enter diameter: ";
  cin>>Diameter;
  
  return Diameter;
}

float CalculateArea(short Diameter)
{
  const float PI{3.14f};
  return (PI * pow((Diameter / 2), 2));
}

void PrintArea(float Area)
{
  cout<<"Circle Area: "<<Area<<endl;
}

int main()
{
  short Diameter{0};

  Diameter = ReadNumbers();
  PrintArea(CalculateArea(Diameter));
  return 0;
}
