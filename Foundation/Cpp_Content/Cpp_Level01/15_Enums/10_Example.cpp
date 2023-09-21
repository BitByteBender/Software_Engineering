#include<iostream>

using std::cout;
using std::endl;
using std::string;

enum enTechBrand{AMD = 0, Nvidia = 1, Intel = 2};
enum enChip{Xtreme = 1, Premium = 2, Standard = 3};
enum enWindows{ Win10 = 0, Win11 = 1};

struct stComponents{
  enTechBrand Brand = enTechBrand::AMD;
  enChip Chip = enChip::Xtreme;
  enWindows Windows = enWindows::Win11;
};

struct stComputerBuild{
  string BuildName{"God Slayer"};
  string BuildDate{"09/20/2023"};
  float Price{25050.25};
  string BuildSeries{"SS+999"};
  stComponents Component;
};

int main()
{
  stComputerBuild Build00, Build01, Build02;

  cout<<"Build Name: "<<Build00.BuildName<<"\n";
  cout<<"Build Date: "<<Build00.BuildDate<<"\n";
  cout<<"Price: $"<<Build00.Price<<"\n";
  cout<<"Build Serie: "<<Build00.BuildSeries<<"\n";
  cout<<"Tech Brand: "<<Build00.Component.Brand<<"\n";
  cout<<"Chip Quality: "<<Build00.Component.Chip<<"\n";
  cout<<"Windows Version: "<<Build00.Component.Windows<<"\n\n";
  
  Build01.BuildName = "Straw Hat";
  Build01.BuildDate = "09/21/2023";
  Build01.Price = 1500.75;
  Build01.BuildSeries = "A+789";
  Build01.Component.Brand = enTechBrand::AMD;
  Build01.Component.Chip = enChip::Standard;
  Build01.Component.Windows = enWindows::Win10;

  cout<<"Build Name: "<<Build01.BuildName<<"\n";
  cout<<"Build Date: "<<Build01.BuildDate<<"\n";
  cout<<"Price: $"<<Build01.Price<<"\n";
  cout<<"Build Serie: "<<Build01.BuildSeries<<"\n";
  cout<<"Tech Brand: "<<Build01.Component.Brand<<"\n";
  cout<<"Chip Quality: "<<Build01.Component.Chip<<"\n";
  cout<<"Windows Version: "<<Build01.Component.Windows<<"\n\n";

  Build02.BuildName = "Excalibur";
  Build02.BuildDate = "09/19/2023";
  Build02.Price = 9500.75;
  Build02.BuildSeries = "S+879";
  Build02.Component.Brand = enTechBrand::Nvidia;
  Build02.Component.Chip = enChip::Premium;
  Build02.Component.Windows = enWindows::Win11;

  cout<<"Build Name: "<<Build02.BuildName<<"\n";
  cout<<"Build Date: "<<Build02.BuildDate<<"\n";
  cout<<"Price: $"<<Build02.Price<<"\n";
  cout<<"Build Serie: "<<Build02.BuildSeries<<"\n";
  cout<<"Tech Brand: "<<Build02.Component.Brand<<"\n";
  cout<<"Chip Quality: "<<Build02.Component.Chip<<"\n";
  cout<<"Windows Version: "<<Build02.Component.Windows<<"\n\n";
  
  
  return 0;
}
