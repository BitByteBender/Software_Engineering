#include <iostream>

using std::cout;
using std::endl;

int main()
{
  //Triangle Area = 1/2 Base * Height
  unsigned short Base{15}, Height{25};
  float AreaOfTriangle = (0.5f * Base) * Height;
  cout<<"Area Of Triangle: "<<AreaOfTriangle<<endl;
  return 0;
}
