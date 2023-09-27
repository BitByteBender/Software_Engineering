#include <iostream>
#include <string>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct stAddress{
  string City{"Kiev"},
    Country{"Ukraine"},
    Place{"st01, Center of Kiev, Penthouse"};

  string Phone{"+234569871"};
};

struct stOwner{
  string FullName{"Oleksandr Guzenko"};
  unsigned Age{45};
  stAddress Address;
  char Gender{'M'};
  bool isMarried{true};
};

struct stMotorYacht{
  string Alias{"Lady Li"};
  string Brand{"Heesen"};
  string BuildDate{"2015"};
  unsigned short Length{50};
  unsigned short Tonnage{499};
  unsigned short HorsePower{4755};
  float MaximumSpeed{16.0f}, CruisingSpeed{13.0f};
  float PriceTag{30.0f};
  float ChartingPrice{350.0f};
  stOwner Owner;
};
  
  
stMotorYacht ReadInfos(stMotorYacht& Vessel){
  
  cout<<"Enter Vessel Alias: ";
  cin>>Vessel.Alias;

  cout<<"Enter Vessel Brand: ";
  cin>>Vessel.Brand;

  cout<<"Enter Vessel BuildDate: ";
  cin>>Vessel.BuildDate;

  cout<<"Enter Vessel Length: ";
  cin>>Vessel.Length;

  cout<<"Enter Vessel Tonnage: ";
  cin>>Vessel.Tonnage;

  cout<<"Enter Vessel HorsePower: ";
  cin>>Vessel.HorsePower;

  cout<<"Enter Vessel Max Speed: ";
  cin>>Vessel.MaximumSpeed;

  cout<<"Enter Vessel CruisingSpeed: ";
  cin>>Vessel.CruisingSpeed;

  cout<<"Enter Vessel PriceTag: ";
  cin>>Vessel.PriceTag;

  cout<<"Enter Vessel Charting Price: ";
  cin>>Vessel.ChartingPrice;

  cout<<"Enter Owner's Full Name: ";
  cin.ignore(1, '\n');
  getline(cin, Vessel.Owner.FullName);

  cout<<"Enter Owner's Age: ";
  cin>>Vessel.Owner.Age;

  cout<<"Enter Owner's City: ";
  cin>>Vessel.Owner.Address.City;

  cout<<"Enter Owner's Country: ";
  cin.ignore(1, '\n');
  getline(cin, Vessel.Owner.Address.Country);

  cout<<"Enter Owner's Full address: ";
  cin.ignore(1, '\n');
  getline(cin, Vessel.Owner.Address.Place);
  
  cout<<"Enter Owner's Phone: ";
  cin>>Vessel.Owner.Address.Phone;
  
  cout<<"Enter Vessel Owner's Gender: ";
  cin>>Vessel.Owner.Gender;

  cout<<"Enter Owner's Marital Status: ";
  cin>>Vessel.Owner.isMarried;

  return Vessel;
}

float ChartingPrice(stMotorYacht Vessel, short Base, short Exponent){
  return Vessel.ChartingPrice * pow(Base, Exponent);
}

void DisplayInfos(stMotorYacht Vessel, string CardStyle){
  cout<<CardStyle<<"\n"
      <<"Vessel Infos"<<"\n"
      <<"Alias: "<<Vessel.Alias<<"\n"
      <<"Brand: "<<Vessel.Brand<<"\n"
      <<"BuildDate: "<<Vessel.BuildDate<<"\n"
      <<"Lenght: "<<Vessel.Length<<" Meters\n"
      <<"Tonnage: "<<Vessel.Tonnage<<" Tons\n"
      <<"Horse Power: "<<Vessel.HorsePower<<" HP\n"
      <<"MaximumSpeed: "<<Vessel.MaximumSpeed<<" Knots\n"
      <<"CruisingSpeed: "<<Vessel.CruisingSpeed<<" Knots\n"
      <<"PriceTag: $"<<Vessel.PriceTag * pow(10, 6)<<"\n"
      <<"Charting Price: $"<<ChartingPrice(Vessel, 10, 3)<<"\n";
  
  cout<<"\nOwner's Infos\n"
      <<"Name: "<<Vessel.Owner.FullName<<"\n"
      <<"Age: "<<Vessel.Owner.Age<<"\n"
      <<"City: "<<Vessel.Owner.Address.City<<"\n"
      <<"Country: "<<Vessel.Owner.Address.Country<<"\n"
      <<"Address: "<<Vessel.Owner.Address.Place<<"\n"
      <<"Phone: "<<Vessel.Owner.Address.Phone<<"\n"
      <<"Gender: "<<Vessel.Owner.Gender<<"\n"
      <<"isMarried: "<<Vessel.Owner.isMarried<<"\n"
      <<CardStyle<<endl;
}

int main()
{
  stMotorYacht Vessel1, Vessel2;
  ReadInfos(Vessel1);
  DisplayInfos(Vessel1, "***************************");

  ReadInfos(Vessel2);
  DisplayInfos(Vessel2, "//////////////////////////////");
  return 0;
}

