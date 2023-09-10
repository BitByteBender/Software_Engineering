#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Radius{0};
  const float PI{3.14};
  
  cout<<"Enter the radius: ";
  cin>>Radius;

  float CircleArea = PI * pow(Radius, 2);
  cout<<"CircleArea: "<<CircleArea<<"\n";
  cout<<"Rounding: "<<round(CircleArea)<<"\n";
  cout<<"Flooring: "<<floor(CircleArea)<<"\n";
  cout<<"Ceiling: "<<ceil(CircleArea)<<endl;
  return 0;
}
