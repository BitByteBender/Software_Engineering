#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::string;

float CalculateArea(short& Num1, short& Num2){
  const float PI{3.14f};
  float TriangleRule = (2.0f * Num1 - Num2) / (2.0f * Num1 + Num2);
  float Area = PI * pow((Num2 / 2), 2) * TriangleRule;
  return Area;
}

void PrintArea(string Message, float Area){

  cout<<Message<<Area<<endl;
}

int main()
{
  short Num1 = 20, Num2 = 10;
  PrintArea("Area: ", CalculateArea(Num1, Num2));
  return 0;
}
