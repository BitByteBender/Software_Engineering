#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

short ReadNumber(std::string Message){
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

float CalculateRectangleArea(short Height, short Diagonal){
  float RectangleArea = Height * sqrt(pow(Diagonal, 2.0f) - pow(Height, 2.0f));
  return RectangleArea;
}

void PrintResult(){
  short Height = ReadNumber("Enter the height: ");
  short Diagonal = ReadNumber("Enter the Diagonal: ");

  cout<<"The Area of a rectangle through the Diagonal side: "<<CalculateRectangleArea(Height, Diagonal)<<endl;
}

int main()
{
  PrintResult();
  return 0;
}
