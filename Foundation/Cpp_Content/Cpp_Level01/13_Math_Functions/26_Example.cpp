#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{

  short SquareSurface{0};
  const float PI{3.14f};
  
  cout<<"Enter the Square surface: ";
  cin>>SquareSurface;

  float Area = PI * pow((SquareSurface / 2.0f), 2.0f);

  cout<<"Area: "<<Area<<"\n";
  cout<<"Rounding: "<<round(Area)<<"\n";
  cout<<"floor: "<<floor(Area)<<"\n";
  cout<<"ceil: "<<ceil(Area)<<endl;
  
  return 0;
}
