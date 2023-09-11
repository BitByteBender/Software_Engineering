#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct strCpu{
  string BrandName{"AMD"};
  short Model{2023};
  short Gen{5};
  string Serie{"Zen5-Ryzen-2023"};
};

int main()
{
  strCpu Cpu;

  cout<<"BrandName: "<<Cpu.BrandName<<"\n";;
  cout<<"Model: "<<Cpu.Model<<"\n";
  cout<<"Gen: "<<Cpu.Gen<<"\n";
  cout<<"Serie: "<<Cpu.Serie<<"\n\n";
  
  Cpu.BrandName = "Intel";
  Cpu.Model = 2022;
  Cpu.Gen = 12;
  Cpu.Serie = "Intel12-AlderLake-2022";

  cout<<"BrandName: "<<Cpu.BrandName<<"\n";;
  cout<<"Model: "<<Cpu.Model<<"\n";
  cout<<"Gen: "<<Cpu.Gen<<"\n";
  cout<<"Serie: "<<Cpu.Serie<<endl;
  return 0;
}

  
