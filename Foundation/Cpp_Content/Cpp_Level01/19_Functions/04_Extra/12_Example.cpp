#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

short ReadNumber(string Message){
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

float CalculateCircleArea(short Num1, short Num2, short Num3){
  const float PI{3.14f};
  float T = (Num1 + Num2 + Num3) / 2;
  return PI * pow((Num1 * Num2 * Num3) / (4 * sqrt(T * (T - Num1) * (T - Num2) * (T - Num3))), 2);
}

void PrintCircleArea(float CircleArea){
  cout<<"Area of a circle described around an arbitrary triangle: "<<CircleArea<<endl;
}

int main()
{
  short Num1 = ReadNumber("Enter 1st number: ");
  short Num2 = ReadNumber("Enter 2nd number: ");
  short Num3 = ReadNumber("Enter 3rd number: ");
  PrintCircleArea(CalculateCircleArea(Num1, Num2, Num3));
  return 0;
}

