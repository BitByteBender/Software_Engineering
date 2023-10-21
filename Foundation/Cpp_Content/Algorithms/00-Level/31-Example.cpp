#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

struct stTriangle
{
  short A{0}, B{0}, C{0};
};

short ReadNumber(std::string Message)
{
  short Number{0};
  
  cout<<Message;
  cin>>Number;
  
  return Number;
}

void ReadTriangle(stTriangle &Triangle)
{
  Triangle.A = ReadNumber("Enter A: ");
  Triangle.B = ReadNumber("Enter B: ");
  Triangle.C = ReadNumber("Enter C: ");
}

float CalculateArea(stTriangle Triangle)
{
  float P = (Triangle.A + Triangle.B + Triangle.C) / 2.0f;
  const float PI{3.14f};
  return (PI * pow(((Triangle.A * Triangle.B * Triangle.C)/(4.0f * sqrt(P * (P - Triangle.A) * (P - Triangle.B) * (P - Triangle.C)))), 2.0f));
}

void PrintArea(float CircleArea)
{
  cout<<"Circle Area: "<<CircleArea<<endl;
}

int main()
{
  stTriangle Triangle;

  ReadTriangle(Triangle);
  PrintArea(CalculateArea(Triangle));
  return 0;
}
