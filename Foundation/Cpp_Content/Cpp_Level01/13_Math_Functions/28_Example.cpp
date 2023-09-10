#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short A{0}, B{0};
  const float PI{3.14f};

  cout<<"Enter A: ";
  cin>>A;

  cout<<"Enter B: ";
  cin>>B;

  float Area = PI * pow(B/2.0f, 2.0f) * ((2.0f * A - B) / (2.0f * A + B));
  
  cout<<"Area: "<<Area<<"\n";
  cout<<"Rounding: "<<round(Area)<<"\n";
  cout<<"Flooring: "<<floor(Area)<<"\n";
  cout<<"Ceiling: "<<ceil(Area)<<endl;
  return 0;
}
