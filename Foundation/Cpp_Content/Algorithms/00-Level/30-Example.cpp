#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

short ReadNumbers(std::string Message)
{
  short Number{0};
  
  cout<<Message;
  cin>>Number;
  
  return Number;
}

float CalculateArea(short Circumference)
{
  const float PI{3.14f};
  return (pow(Circumference, 2.0f) / (pow(2.0f, 2.0f) * PI));
}

void PrintArea(float CircleArea)
{
  cout<<"Circle Area: "<<CircleArea<<endl;
}

int main()
{
  short Circumference{0};

  Circumference = ReadNumbers("Enter the circumference: ");
  PrintArea(CalculateArea(Circumference));
  return 0;
}
