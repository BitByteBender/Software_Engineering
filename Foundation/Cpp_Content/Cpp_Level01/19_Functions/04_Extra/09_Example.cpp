#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

short ReadPositiveNumber(){
  short Number{0};

  cout<<"Enter a number: ";
  cin>>Number;

  return Number;
}

float CalculateCircleArea(short Square){
  const float PI{3.14f};
  return PI * pow((Square / 2), 2);
}

void PrintCircleAreaInscribedInASquare(float AreaOfCircle){
  cout<<"Area of a Circle Inscribed in a Square: "<<AreaOfCircle<<endl;
}

int main()
{
  
  PrintCircleAreaInscribedInASquare(CalculateCircleArea(ReadPositiveNumber()));
  return 0;
}
