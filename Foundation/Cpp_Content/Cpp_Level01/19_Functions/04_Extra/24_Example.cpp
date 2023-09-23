#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void ReadNumbers(short &Base, short &Height){

  cout<<"Enter base: ";
  cin>>Base;

  cout<<"Enter height: ";
  cin>>Height;

}

float CalculateRectangleArea(short &Base, short &Height){
  float Area = Base * Height;
  return Area;
}

void PrintArea(float Area){
  cout<<"Area: "<<Area<<endl;
}

int main()
{
  short Base = 0, Height = 0;
  ReadNumbers(Base, Height);
  PrintArea(CalculateRectangleArea(Base, Height));
  return 0;
}


  
