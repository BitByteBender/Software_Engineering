#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Circumference{0};

  cout<<"Enter a Circumference: ";
  cin>>Circumference;

  const float PI{3.14f};
  
  float AreaOfCircle = PI * (pow(Circumference, 2) / pow((2 * PI), 2));//(pow(Circumference, 2) / pow(2, 2) * PI))
  cout<<"Area of a circle along the Circumference: "<<AreaOfCircle<<"\n";
  cout<<"Using ceil function: "<<ceil(AreaOfCircle)<<endl;
  return 0;
}
