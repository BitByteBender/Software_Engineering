#include <iostream>
#include "math.h"

using std::cout;
using std::endl;


float CalculateCircleArea(short Number1, short Number2){
  const float PI{3.14f};
  return PI * (pow(Number2, 2.0f) / 4.0f) * ( (2.0f * Number1 - Number2) / (2.0f * Number1 + Number2) );
}

void PrintCircleArea(float CircleArea){

  cout<<"Area of a circle Inscribed in an isosceles triangle: "<<CircleArea<<endl;
}

int main()
{
  short Number1{20}, Number2{10};
  PrintCircleArea(CalculateCircleArea(Number1, Number2));
  return 0;
}
