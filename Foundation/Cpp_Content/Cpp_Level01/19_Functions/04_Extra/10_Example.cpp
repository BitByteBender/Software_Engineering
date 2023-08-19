#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

short ReadNumber(){

  short Number{0};

  cout<<"Enter a positive number: ";
  cin>>Number;

  return Number;
}

float CalculateCircleAreaAlongCircumference(short Circumference){
  const float PI{3.14f};
  return pow(Circumference, 2) / (PI * 4);
}

void PrintCircleAreaAlongCircumference(float CircleArea){
  cout<<"Circle Area Along the Circumference: "<<round(CircleArea)<<endl;
}

int main()
{
  short Circumference = ReadNumber();
  PrintCircleAreaAlongCircumference(CalculateCircleAreaAlongCircumference(Circumference));
  return 0;
}
