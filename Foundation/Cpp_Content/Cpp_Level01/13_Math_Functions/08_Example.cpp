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
  float RectangleArea = X * sqrt(pow(Y, 2) - pow(X, 2));
  cout<<"Area of a rectangle: "<<RectangleArea<<"\n";
  cout<<"Result using Ceil function: "<<ceil(RectangleArea)<<endl;
  return 0;
}
