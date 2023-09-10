#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short X{0}, Y{0}, Z{0};

  cout<<"Enter X: ";
  cin>>X;

  cout<<"Enter Y: ";
  cin>>Y;

  cout<<"Enter Z: ";
  cin>>Z;

  unsigned int Calculation = X + Z + Y;
  cout<<"Using Pow: "<<pow(Calculation, 3)<<"\n";
  cout<<"Using Sqrt: "<<sqrt(pow(Calculation, 3))<<"\n";
  cout<<"Using Round: "<<round(sqrt(pow(Calculation, 3)))<<"\n";
  cout<<"Using Floor: "<<floor(sqrt(pow(Calculation, 3)))<<"\n";
  cout<<"Using Ceil: "<<ceil(sqrt(pow(Calculation, 3)))<<"\n\n";

  return 0;
}
