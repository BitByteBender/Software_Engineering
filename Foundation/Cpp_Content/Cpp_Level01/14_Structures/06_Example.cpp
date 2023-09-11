#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct strCar{
  string BrandName{"Empty"};
  string Type{"Empty"};
  short Model{0};
};

int main()
{
  strCar Car1, Car2, Car3;

  Car1.BrandName = "Mustang";
  Car1.Type = "Shelby";
  Car1.Model = 1996;

  cout<<"BrandName: "<<Car1.BrandName<<"\n";
  cout<<"Type: "<<Car1.Type<<"\n";
  cout<<"Model: "<<Car1.Model<<"\n\n";

  Car2.BrandName = "Lamborghini";
  Car2.Type = "Veneno";
  Car2.Model = 2014;

  cout<<"BrandName: "<<Car2.BrandName<<"\n";
  cout<<"Type: "<<Car2.Type<<"\n";
  cout<<"Model: "<<Car2.Model<<"\n\n";

  Car3.BrandName = "Mclaren";
  Car3.Type = "765LT";
  Car3.Model = 2021;

  cout<<"BrandName: "<<Car3.BrandName<<"\n";
  cout<<"Type: "<<Car3.Type<<"\n";
  cout<<"Model: "<<Car3.Model<<endl;

  
  return 0;
}
