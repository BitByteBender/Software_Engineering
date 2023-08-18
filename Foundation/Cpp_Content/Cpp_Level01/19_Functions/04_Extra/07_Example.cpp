#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

float CalculateCircleArea(short Radius){
  const float PI{3.14f};
  return PI * pow(Radius, 2.0f);
}

void PrintCircleArea(float CircleArea){

  cout<<"Area of a cricle: "<<CircleArea<<endl;
}

int main()
{
  short Radius{5};
  PrintCircleArea(CalculateCircleArea(Radius));
  return 0;
}
