#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

void ReadNumber(short& Number){

  cout<<"Enter a number: ";
  cin>>Number;
}

float CalculateArea(short& Num){
  const float PI{3.14};
  float CircleArea = PI * pow(Num, 2);
  return CircleArea;
}

void PrintArea(float Area){
  cout<<"Area: "<<Area<<endl;
}

int main()
{
  short Num = 0;
  ReadNumber(Num);
  PrintArea(CalculateArea(Num));
  return 0;
}
