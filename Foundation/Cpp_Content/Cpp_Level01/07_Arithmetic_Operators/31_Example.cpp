#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short Circumference{0};
  const float PI{3.14f};
  float Area{0};

  cout<<"Enter the Circumference: ";
  cin>>Circumference;

  Area = ((Circumference * Circumference) / (PI * 4));
  cout<<Area<<endl;
  return 0;
}
