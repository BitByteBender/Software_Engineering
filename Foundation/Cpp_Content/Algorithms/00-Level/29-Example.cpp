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

float CalculateArea(short SquareArea)
{
  const float PI{3.14f};
  return (PI * (pow(SquareArea, 2) / pow(2, 2)));
}

void PrintArea(float CircleArea)
{
  cout<<"Circle Area: "<<CircleArea<<endl;
}

int main()
{
  short Square{0};

  Square = ReadNumbers("Enter square area: ");
  PrintArea(CalculateArea(Square));
  return 0;
}
