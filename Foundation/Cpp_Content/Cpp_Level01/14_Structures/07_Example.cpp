#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct stAddress{
  string Location{"Empty"};
  string City{"Empty"};
  string Country{"Empty"};
};

struct stFounder{
  string FirstName{"Empty"};
  string LastName{"Empty"};
  unsigned short Age{0};
  string Phone{"Empty"};
  string Origin{"Empty"};
  stAddress FounderAdr;
};

struct stRestaurantData{
  string Name{"Empty"};
  unsigned short FoundedIn{0};
  stFounder Owner;
  stAddress RestaurantAdr;
  bool isOpened{false};
};

int main()
{
  stRestaurantData Restaurant1, Restaurant2;

  Restaurant1.Name = "Kyoto";
  Restaurant1.FoundedIn = 2002;
  Restaurant1.Owner.FirstName = "Soufiane";
  Restaurant1.Owner.LastName = "Sdg";
  Restaurant1.Owner.Age = 30;
  Restaurant1.Owner.Phone = "+2126999999";
  Restaurant1.Owner.Origin = "Jupiter";
  Restaurant1.Owner.FounderAdr.City = "London";
  Restaurant1.Owner.FounderAdr.Country = "United Kingdom";
  Restaurant1.RestaurantAdr.Location = "Negro st101, london";

  cout<<"Restaurant Name: "<<Restaurant1.Name<<"\n";
  cout<<"Founded In: "<<Restaurant1.FoundedIn<<"\n";
  cout<<"Owner's name: "<<Restaurant1.Owner.FirstName + " " + Restaurant1.Owner.LastName<<"\n";
  cout<<"Owner's Age: "<<Restaurant1.Owner.Age<<"\n";
  cout<<"Owner's Phone: "<<Restaurant1.Owner.Phone<<"\n";
  cout<<"Owner's Origin: "<<Restaurant1.Owner.Origin<<"\n";
  cout<<"Owner's City: "<<Restaurant1.Owner.FounderAdr.City<<"\n";
  cout<<"Owner's Country: "<<Restaurant1.Owner.FounderAdr.Country<<"\n";
  cout<<"Restaurant Location: "<<Restaurant1.RestaurantAdr.Location<<"\n\n";

  Restaurant2.Name = "LocaLoca";
  Restaurant2.FoundedIn = 1956;
  Restaurant2.Owner.FirstName = "Gusta";
  Restaurant2.Owner.LastName = "Estas";
  Restaurant2.Owner.Age = 38;
  Restaurant2.Owner.Phone = "+21269789999";
  Restaurant2.Owner.FounderAdr.Country = "Morocco";
  Restaurant2.RestaurantAdr.Location = "Somewhere st99, in Morocco";

  cout<<"Restaurant Name: "<<Restaurant2.Name<<"\n";
  cout<<"Founded In: "<<Restaurant2.FoundedIn<<"\n";
  cout<<"Owner's name: "<<Restaurant2.Owner.FirstName + " " + Restaurant2.Owner.LastName<<"\n";
  cout<<"Owner's Age: "<<Restaurant2.Owner.Age<<"\n";
  cout<<"Owner's Phone: "<<Restaurant2.Owner.Phone<<"\n";
  cout<<"Owner's Country: "<<Restaurant2.Owner.FounderAdr.Country<<"\n";
  cout<<"Restaurant Location: "<<Restaurant2.RestaurantAdr.Location<<endl;

  return 0;
}
