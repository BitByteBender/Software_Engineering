#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadNumbers(std::string Message){

  short Num{0};

  cout<<Message;
  cin>>Num;

  return Num;
}

float CalculateArea(short A, short D){
  float Area = A * sqrt(pow(D, 2) - pow(A, 2));
  return Area;
}

void PrintArea(float Area){
  cout<<"Area: "<<Area<<endl;
}

int main()
{
  short A = ReadNumbers("Enter A: ");
  short D = ReadNumbers("Enter D: ");
  PrintArea(CalculateArea(A, D));
  return 0;
}
