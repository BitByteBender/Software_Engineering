#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::string;

struct strCarDetails{
  string BrandName{"Aston Martin"};
  string CarName{"Dbs Superlegera"};
  string Type{"GT"};
  string Color{"Emerald Green"};
  unsigned short ManufacturedNumber{115};
  string ManufacturedDate{"2nd July, 2023"};
};


int main()
{
  string PrintStars{"*********************"};
  
  strCarDetails Car_1, Car_2, Car_3;

  cout<<PrintStars<<"\n";
  cout<<"Brand: " + Car_1.BrandName<<"\n"
      <<"Name: " + Car_1.CarName<<"\n"
      <<"Type: " + Car_1.Type<<"\n"
      <<"Color: " + Car_1.Color<<"\n"
      <<"ManuNumber: "<<Car_1.ManufacturedNumber<<"\n"
      <<"ManuDate: " + Car_1.ManufacturedDate<<"\n";


  Car_2.BrandName = "Mclaren";
  Car_2.CarName = "675LT";
  Car_2.Type = "Supercar";
  Car_2.Color = "Turqoise";
  Car_2.ManufacturedNumber = 15;
  Car_2.ManufacturedDate = "2nd June, 2022";

  cout<<PrintStars<<"\n";
  cout<<"Brand: " + Car_2.BrandName<<"\n"
      <<"Name: " + Car_2.CarName<<"\n"
      <<"Type: " + Car_2.Type<<"\n"
      <<"Color: " + Car_2.Color<<"\n"
      <<"ManuNumber: "<<Car_2.ManufacturedNumber<<"\n"
      <<"ManuDate: " + Car_2.ManufacturedDate<<"\n";
  

  Car_3.BrandName = "Tuatara";
  Car_3.CarName = "SSC";
  Car_3.Type = "Hypercar";
  Car_3.Color = "Hermes White";
  Car_3.ManufacturedNumber = 03;
  Car_3.ManufacturedDate = "2nd March, 2022";

  cout<<PrintStars<<"\n";
  cout<<"Brand: " + Car_3.BrandName<<"\n"
      <<"Name: " + Car_3.CarName<<"\n"
      <<"Type: " + Car_3.Type<<"\n"
      <<"Color: " + Car_3.Color<<"\n"
      <<"ManuNumber: "<<Car_3.ManufacturedNumber<<"\n"
      <<"ManuDate: " + Car_3.ManufacturedDate<<"\n";
  cout<<PrintStars<<endl;
    
  return 0;
}
