#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

float CalculateArea(short Number){
  const float PI{3.14f};
  float Area = pow(Number/2, 2) * (1/PI);
  return Area;
}

void PrintArea(float Area){
  cout<<"Area: "<<CalculateArea(Area)<<endl;
}

int main()
{
  short Num = 20;
  PrintArea(Num);
  return 0;
}
