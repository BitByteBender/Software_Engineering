#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

short ReadNumbers()
{
  short Radius{0};
  
  cout<<"Enter radius: ";
  cin>>Radius;
  
  return Radius;
}

float CalculateArea(short Radius)
{
  const float PI{3.14f};
  return (PI * pow(Radius, 2));
}

void PrintArea(float Area)
{
  cout<<"Circle Area: "<<Area<<endl;
}

int main()
{
  short Radius{0};

  Radius = ReadNumbers();
  PrintArea(CalculateArea(Radius));
  return 0;
}
