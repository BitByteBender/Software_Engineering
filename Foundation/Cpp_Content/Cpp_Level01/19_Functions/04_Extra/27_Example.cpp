#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void ReadDiagonal(short& Diagonal, string Message){
  cout<<Message;
  cin>>Diagonal;
}

float CalculateArea(short& Diagonal){
  const float PI{3.14f};

  float Area = PI * pow((Diagonal / 2), 2);
  return Area;
}

void PrintArea(float Area){
  cout<<"Area: "<<Area<<endl;
}

int main()
{
  short Diagonal = 0;
  ReadDiagonal(Diagonal, "Enter a number: ");
  PrintArea(CalculateArea(Diagonal));
  return 0;
}
