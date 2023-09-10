#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short X{0}, Y{0}, Z{0}, K{0};

  cout<<"Enter X: ";
  cin>>X;

  cout<<"Enter Y: ";
  cin>>Y;

  cout<<"Enter Z: ";
  cin>>Z;

  cout<<"Enter K(this will be used as an exponent): ";
  cin>>K;

  unsigned int Calculation = X + Z + Y;
  cout<<"Using Pow: "<<pow(Calculation, K)<<"\n";
  cout<<"Using Sqrt: "<<sqrt(pow(Calculation, K))<<"\n";
  cout<<"Using Round: "<<round(sqrt(pow(Calculation, K)))<<"\n";
  cout<<"Using Floor: "<<floor(sqrt(pow(Calculation, K)))<<"\n";
  cout<<"Using Ceil: "<<ceil(sqrt(pow(Calculation, K)))<<"\n\n";

  cout<<"Using Sqrt: "<<sqrt(Calculation)<<"\n";
  cout<<"Using Pow: "<<pow(sqrt(Calculation), K)<<"\n";
  cout<<"Using Round: "<<round(pow(sqrt(Calculation), K))<<"\n";
  cout<<"Using Floor: "<<floor(pow(sqrt(Calculation), K))<<"\n";
  cout<<"Using Ceil: "<<ceil(pow(sqrt(Calculation), K))<<endl;
  return 0;
}
