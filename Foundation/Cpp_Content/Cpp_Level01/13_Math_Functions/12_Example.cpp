#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short X{0}, Y{0};

  cout<<"Enter X: ";
  cin>>X;
  
  cout<<"Enter Y: ";
  cin>>Y;

  const float PI{3.14f};
  float CircleArea = PI * pow((X / 2.0f), 2.0f) * ((2.0f * Y - X) / (2.0f * Y + X));
  cout<<"Area of a circle: "<<CircleArea<<"\n";
  cout<<"Using floor function: "<<floor(CircleArea)<<endl;
  return 0;
}
