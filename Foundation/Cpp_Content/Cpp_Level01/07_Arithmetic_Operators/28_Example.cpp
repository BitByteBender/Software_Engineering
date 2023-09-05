#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short Base{0};
  short Height{0};
  float Area{0};

  cout<<"Enter the Base: ";
  cin>>Base;

  cout<<"Enter the Height: ";
  cin>>Height;

  Area = (0.5f * Base) * Height;

  cout<<"Area of triangle is: "<<Area<<endl;
  return 0;
}
