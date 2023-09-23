#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

short ReadNumber(string Message){
  short Num{0};

  cout<<Message;
  cin>>Num;

  return Num;
}

float CalculateArea(short Number){
  const float PI{3.14f};
  float Area = PI * pow((Number / 2), 2);
  return Area;
}

void PrintArea(float Area){
  cout<<"Area: "<<CalculateArea(Area)<<endl;
}

int main()
{
  short Number = ReadNumber("Enter a number: ");
  PrintArea(Number);
  return 0;
}
