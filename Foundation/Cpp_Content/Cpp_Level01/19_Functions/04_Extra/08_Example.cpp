#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

short ReadDiameter(std::string Message){
  short Diameter{0};
  cout<<Message;
  std::cin>>Diameter;
  return Diameter;
}

float CalculateCircleArea(short Diameter){
  const float PI{3.14f};
  return (PI * pow(Diameter, 2)) / 4;
}

void PrintCircleAreaThroughDiameter(float CircleArea){
  cout<<"Circle Area Through Diameter: "<<CircleArea<<endl;
}

int main()
{
  short Diameter = ReadDiameter("What's the Diameter? ");
  PrintCircleAreaThroughDiameter(CalculateCircleArea(Diameter));
  return 0;
}
