#include <iostream>

using std::cout;
using std::endl;

enum enBrand{Mclaren = 0, Zenvo = 1, AstonMartin = 2, RollsRoyce = 3, HongQi = 4};

int main()
{
  enBrand Brands;

  Brands = enBrand::AstonMartin;
  cout<<"My Favourite Brand: "<<Brands<<"\n";
  
  Brands = enBrand::HongQi;
  cout<<"My Favourite Brand: "<<Brands<<"\n";
  
  Brands = enBrand::Mclaren;
  cout<<"My Favourite Brand: "<<Brands<<"\n";
    
  Brands = enBrand::Zenvo;
  cout<<"My Favourite Brand: "<<Brands<<"\n";
  
  Brands = enBrand::RollsRoyce;
  cout<<"My Favourite Brand: "<<Brands<<endl;
  return 0;
}
