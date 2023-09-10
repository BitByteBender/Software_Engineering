#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

int main()
{
  short R{8};

  cout<<"Square root of "<<R<<" is: "<<sqrt(R)<<"\n";
  cout<<"Rounding Sqrt("<<R<<"): "<<round(sqrt(R))<<"\n\n";

  R = ++R * 2 + 3 + R++;//30
  cout<<"Square root of "<<R<<" is: "<<sqrt(R)<<"\n";
  cout<<"rounding Sqrt("<<R<<"): "<<round(sqrt(R))<<endl;
  
  return 0;
}
