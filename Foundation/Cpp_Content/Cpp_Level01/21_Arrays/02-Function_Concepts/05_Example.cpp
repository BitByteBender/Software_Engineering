#include <iostream>
#include "cmath"

using std::cout;
using std::cin;
using std::endl;

void ReadData(short Radius[4]){
  cout<<"Enter 1st Radius: ";
  cin>>Radius[0];

  cout<<"Enter 2nd Radius: ";
  cin>>Radius[1];

  cout<<"Enter 3rd Radius: ";
  cin>>Radius[2];

  cout<<"Enter 4th Radius: ";
  cin>>Radius[3];
}


void PrintCircleArea(short Radius[4], float Areas[4]){


  cout<<"Radius:\nAt position 0: "<<Radius[0]<<"\n"
      <<"At position 1: "<<Radius[1]<<"\n"
      <<"At position 2: "<<Radius[2]<<"\n"
      <<"At position 3: "<<Radius[3]<<"\n";

  cout<<"Circle Areas:\nAt index 0: "<<Areas[0]<<"\n"
      <<"At index 1: "<<Areas[1]<<"\n"
      <<"At index 2: "<<Areas[2]<<"\n"
      <<"At index 3: "<<Areas[3]<<endl;
}

int main()
{
  short Radius[4] = {0, 0, 0, 0};
  const float PI{3.14f};
  ReadData(Radius);
  float Areas[4] = {float(PI * pow(Radius[0], 2)), float(PI * pow(Radius[1], 2)), float(PI * pow(Radius[2], 2)), float(PI * pow(Radius[3], 2))};
  PrintCircleArea(Radius, Areas);
  return 0;
}
