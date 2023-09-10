#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short C{0};
  const float PI{3.14f};
  
  cout<<"Enter the circumference: ";
  cin>>C;

  float Area = pow(C, 2.0f) / (4.0f * PI);

  cout<<"Area: "<<Area<<"\n";
  cout<<"Rounding: "<<round(Area)<<"\n";
  cout<<"Flooring: "<<floor(Area)<<"\n";
  cout<<"Ceiling: "<<ceil(Area)<<endl;
  return 0;
}
