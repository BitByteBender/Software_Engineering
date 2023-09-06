#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  short A{0}, B{0};
  const float PI{3.14f};
  float CircleArea{0};

  cout<<"Enter A: ";
  cin>>A;

  cout<<"Enter B: ";
  cin>>B;

  CircleArea = PI * ((B * B) / 4.0f) * ((2.0f * A - B) / (2.0f * A + B));

  cout<<CircleArea<<endl;
  return 0;
}

