#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
  unsigned short Square{0};

  cout<<"Enter a number: ";
  cin>>Square;

  const float PI{3.14f};
  float AreaOfCircle = PI * (pow(Square, 2) / 4);
  cout<<"Circle Area: "<<AreaOfCircle<<"\n";
  cout<<"Using ceiling function: "<<ceil(AreaOfCircle)<<endl;
  return 0;
}
