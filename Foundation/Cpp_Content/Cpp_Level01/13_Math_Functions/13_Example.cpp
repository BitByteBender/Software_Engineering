#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short X{0}, Y{0}, K{0};

  cout<<"Enter X: ";
  cin>>X;
  
  cout<<"Enter Y: ";
  cin>>Y;
  
  cout<<"Enter K: ";
  cin>>K;

  const float PI{3.14f};
  unsigned short Surface = (X + Y + K) / 2;
  float CircleArea = PI * pow(((X * Y * K) / (4 * sqrt(Surface * (Surface - X)*(Surface - Y)*(Surface - K)))), 2.0f);
  cout<<"Circle Area: "<<CircleArea<<"\n";
  cout<<"Using floor function: "<<floor(CircleArea)<<endl;
  return 0;
}
