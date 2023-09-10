#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short A{0}, B{0}, C{0};
  const float PI{3.14f};

  cout<<"Enter A: ";
  cin>>A;

  cout<<"Enter B: ";
  cin>>B;

  cout<<"Enter C: ";
  cin>>C;

  float T = (A + B + C) / 2.0f;
  float Area = PI * pow((A * B * C) / (4.0f * sqrt(T * (T - A)*(T - B)*(T - C))), 2.0f);

  cout<<"Area: "<<Area<<"\n";
  cout<<"Rounding: "<<round(Area)<<"\n";
  cout<<"Flooring: "<<floor(Area)<<"\n";
  cout<<"Ceiling: "<<ceil(Area)<<endl;
  return 0;
}
