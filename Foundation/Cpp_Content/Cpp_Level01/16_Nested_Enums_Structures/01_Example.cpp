#include <iostream>

using std::cout;
using std::endl;
using std::string;

enum enBrands{ PalmerJhonson = 1, Riva = 2, SunSeeker = 3, Pershing = 4, Bugati = 5, Lamborghini = 6};
enum enOptions{ Entry = 0, Luxury = 1, Modena = 2, FullOption = 3};
enum enType{ MotorBoat = 0, Super = 1, Mega = 2, SuperMega = 3};

struct stYachtBrand{
  enBrands BrandName;
  string Model{"Empty"}, Serie{"Empty"};
  unsigned short CraftingNumber{0};
  enType Type;
  enOptions Option;
};


int main()
{
  stYachtBrand Yacht1, Yacht2, Yacht3;

  string PrintStars{"*********************************"};

  cout<<PrintStars<<"\n"
      <<"Brand name: "<<Yacht1.BrandName<<"\n"
      <<"Model: "<<Yacht1.Model<<"\n"
      <<"Serie: "<<Yacht1.Serie<<"\n"
      <<"Crafting N:"<<Yacht1.CraftingNumber<<"\n"
      <<"Type: "<<(Yacht1.Type = enType::MotorBoat)<<"\n"
      <<"Option: "<<(Yacht1.Option = enOptions::Entry)<<"\n"
      <<PrintStars<<"\n";


  Yacht2.BrandName = enBrands::PalmerJhonson;
  Yacht2.Model = "2023";
  Yacht2.Serie = "128Ft";
  Yacht2.CraftingNumber = 15;
  Yacht2.Type = enType::Mega;
  Yacht2.Option = enOptions::FullOption;

  cout<<PrintStars<<"\n"
      <<"Brand name: "<<Yacht2.BrandName<<"\n"
      <<"Model: "<<Yacht2.Model<<"\n"
      <<"Serie: "<<Yacht3.Serie<<"\n"
      <<"Crafting N:"<<Yacht2.CraftingNumber<<"\n"
      <<"Type: "<<Yacht2.Type<<"\n"
      <<"Option: "<<Yacht2.Option<<"\n"
      <<PrintStars<<"\n";

  Yacht3.BrandName = enBrands::Riva;
  Yacht3.Model = "2022";
  Yacht3.Serie = "72Ft";
  Yacht3.CraftingNumber = 07;
  Yacht3.Type = enType::Super;
  Yacht3.Option = enOptions::Luxury;

  cout<<PrintStars<<"\n"
      <<"Brand name: "<<Yacht3.BrandName<<"\n"
      <<"Model: "<<Yacht3.Model<<"\n"
      <<"Serie: "<<Yacht3.Serie<<"\n"
      <<"Crafting N:"<<Yacht3.CraftingNumber<<"\n"
      <<"Type: "<<Yacht3.Type<<"\n"
      <<"Option: "<<Yacht3.Option<<"\n"
      <<PrintStars<<endl;

  
  
  return 0;
}
