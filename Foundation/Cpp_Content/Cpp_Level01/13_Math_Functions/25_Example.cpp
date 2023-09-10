#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Diameter{0};
  const float PI{3.14f};
  
  cout<<"Enter the diameter: ";
  cin>>Diameter;

  //1st Method
  float Area = (PI * pow(Diameter, 2.0f)) / 4.0f;

  cout<<"Area: "<<Area<<"\n";
  cout<<"Rounding: "<<round(Area)<<"\n";
  cout<<"floor: "<<floor(Area)<<"\n";
  cout<<"ceil: "<<ceil(Area)<<"\n\n";

  //2nd Method
  Area = PI * pow((Diameter / 2.0f), 2.0f);

  cout<<"Area: "<<Area<<"\n";
  cout<<"Rounding: "<<round(Area)<<"\n";
  cout<<"floor: "<<floor(Area)<<"\n";
  cout<<"ceil: "<<ceil(Area)<<endl;
  return 0;
}
