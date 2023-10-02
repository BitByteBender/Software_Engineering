#include <iostream>
#include "cmath"

using std::cout;
using std::cin;
using std::endl;

short ReadNumber(std::string Message){
  short Num{0};

  cout<<Message;
  cin>>Num;

  return Num;
}

float CircleArea(short Num){
  const float PI{3.14f};
  return PI * pow((Num / 2.0f), 2.0f);
}

void PrintArea(float Area, short CircleArr[]){
  cout<<"Area is: "<<Area<<"\n";
  cout<<"At index 0: "<<CircleArr[0]<<"\n";
  cout<<"At index 1: "<<CircleArr[1]<<"\n";
  cout<<"At index 2: "<<CircleArr[2]<<"\n";
  cout<<"At index 3: "<<CircleArr[3]<<"\n";
}

int main()
{
  short Diameter = ReadNumber("Enter the diameter: ");
  float Area = CircleArea(Diameter);
  short CircleArr[4] = {Diameter, short(Area), short(Area * 2),  short(pow(Area, 2))};
  PrintArea(Area, CircleArr);
  return 0;
}
