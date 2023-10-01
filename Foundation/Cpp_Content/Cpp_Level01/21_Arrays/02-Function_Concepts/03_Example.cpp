#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ReadNumber(short &Base, short &Height){

  cout<<"Enter a number: ";
  cin>>Base;

  cout<<"Enter a 2nd number: ";
  cin>>Height;

}

float CalculateArea(short &Base, short &Height){
  return (0.5f * Base) * Height;
}

void PrintArea(float Area, float AreaArr[]){
  cout<<"The Area is: "<<Area<<"\n";

  cout<<"At position 0: "<<AreaArr[0]<<"\n";
  cout<<"At positon 1: "<<AreaArr[1]<<"\n";
  cout<<"At positon 2: "<<AreaArr[2]<<endl;
}
 

int main()
{
  short Base{0}, Height{0};
  ReadNumber(Base, Height);
  float Area = CalculateArea(Base, Height);
  float AreaArr[3] = {float(Base), float(Height), Area};
  PrintArea(Area, AreaArr);
  return 0;
}
