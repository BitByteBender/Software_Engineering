#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short H{0}, D{0};

  cout<<"Enter H: ";
  cin>>H;

  cout<<"Enter D: ";
  cin>>D;

  //Method1
  float Area = H * sqrt(pow(D, 2.0f) - pow(H, 2.0f));

  cout<<"Area is: "<<Area<<"\n";
  cout<<"Rounding Area: "<<round(Area)<<"\n";
  cout<<"Flooring Area: "<<floor(Area)<<"\n";
  cout<<"Ceiling Area: "<<ceil(Area)<<"\n\n";

  return 0;
}
