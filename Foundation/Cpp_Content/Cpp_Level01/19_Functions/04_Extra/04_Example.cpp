#include <iostream>

using std::cout;
using std::endl;
using std::cin;

short ReadInputs(std::string Message){
  short Number{0};
  
  cout<<Message;
  cin>>Number;

  return Number;
}

float CalculateTriangleArea(short Base, short Height){
  return (0.5f * Base) * Height;
}

void PrintTriangleArea(float TriangleArea){
  cout<<"TriangleArea is : "<<TriangleArea<<endl;
}

int main()
{
  short Base = ReadInputs("Enter the base: ");
  short Height = ReadInputs("Enter the height: ");
  PrintTriangleArea(CalculateTriangleArea(Base, Height));
  return 0;
}
