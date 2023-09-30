#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
  short A{0}, B{0};
  short Sum{0};
  float Calculation1{0.0f}, Calculation2{0.0f};
  
  cout<<"Enter A: ";
  cin>>A;

  cout<<"Enter B: ";
  cin>>B;

  Sum = A + B;
  Calculation1 = (pow(Sum, 2.0f) / 5.0f) * 9.25f;
  floor(Calculation1);

  Calculation2 = Calculation1 / Sum;
  ceil(Calculation2);
  
  float Arr1[3] = {float(Sum), Calculation1, Calculation2};

  cout<<"Sum: "<<Sum<<"\n";
  cout<<"Calculation 1: "<<Calculation1<<"\n";
  cout<<"Calculation 2: "<<Calculation2<<"\n";
  cout<<"Arr1 at index 0: "<<Arr1[0]<<"\nArr1 at index 1: "<<Arr1[1]<<"\nArr1 at index 2: "<<Arr1[2]<<endl;
  
  return 0;
}
