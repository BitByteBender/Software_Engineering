#include <iostream>

using std::cout;
using std::endl;
using std::cin;
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

struct stRestaurant{
  string Name{"Empty"};
  unsigned short FoundedIn{0};
  stFounder Owner;
  stAddress RestaurantAdr;
  bool isOpened{false};
};

int main()
{
  stRestaurant Restau1, Restau2, Restau3;

  cout<<"Enter restaurant name: ";
  cin>>Restau1.Name;

  cout<<"Founded in ?: ";    
  cin>>Restau1.FoundedIn;

  cout<<"Owner's FirstName: ";
  cin>>Restau1.Owner.FirstName;

  cout<<"Owner's LastName: ";
  cin>>Restau1.Owner.LastName;

  cout<<"Owner's Age: ";
  cin>>Restau1.Owner.Age;

  cout<<"Owner's Phone: ";
  cin>>Restau1.Owner.Phone;

  cout<<"Owner's Origin: ";
  cin>>Restau1.Owner.Origin;

  cout<<"Owner's addresse: ";
  cin>>Restau1.Owner.FounderAdr.City;

  cout<<"Owner's Country: ";
  cin>>Restau1.Owner.FounderAdr.Country;

  cout<<"Restaurant Location: ";
  cin>>Restau1.RestaurantAdr.Location;

  cout<<"Restaurant Name: "<<Restau1.Name<<"\n";
  cout<<"Founded In: "<<Restau1.FoundedIn<<"\n";
  cout<<"Owner's name: "<<Restau1.Owner.FirstName + " " + Restau1.Owner.LastName<<"\n";
  cout<<"Owner's Age: "<<Restau1.Owner.Age<<"\n";
  cout<<"Owner's Phone: "<<Restau1.Owner.Phone<<"\n";
  cout<<"Owner's Origin: "<<Restau1.Owner.Origin<<"\n";
  cout<<"Owner's City: "<<Restau1.Owner.FounderAdr.City<<"\n";
  cout<<"Owner's Country: "<<Restau1.Owner.FounderAdr.Country<<"\n";
  cout<<"Restaurant Location: "<<Restau1.RestaurantAdr.Location<<"\n\n";

  cout<<"Enter restaurant name: ";
  cin>>Restau2.Name;

  cout<<"Founded in ?: ";    
  cin>>Restau2.FoundedIn;

  cout<<"Owner's FirstName: ";
  cin>>Restau2.Owner.FirstName;

  cout<<"Owner's LastName: ";
  cin>>Restau2.Owner.LastName;

  cout<<"Owner's Age: ";
  cin>>Restau2.Owner.Age;

  cout<<"Owner's Phone: ";
  cin>>Restau2.Owner.Phone;

  cout<<"Owner's Country: ";
  cin>>Restau2.Owner.FounderAdr.Country;

  cout<<"Restaurant Location: ";
  cin>>Restau2.RestaurantAdr.Location;

  cout<<"Restaurant Name: "<<Restau2.Name<<"\n";
  cout<<"Founded In: "<<Restau2.FoundedIn<<"\n";
  cout<<"Owner's name: "<<Restau2.Owner.FirstName + " " + Restau2.Owner.LastName<<"\n";
  cout<<"Owner's Age: "<<Restau2.Owner.Age<<"\n";
  cout<<"Owner's Phone: "<<Restau2.Owner.Phone<<"\n";
  cout<<"Owner's Country: "<<Restau2.Owner.FounderAdr.Country<<"\n";
  cout<<"Restaurant Location: "<<Restau2.RestaurantAdr.Location<<"\n\n";

  cout<<"Enter restaurant name: ";
  cin>>Restau3.Name;

  cout<<"Founded in ?: ";    
  cin>>Restau3.FoundedIn;

  cout<<"Owner's FirstName: ";
  cin>>Restau3.Owner.FirstName;

  cout<<"Owner's LastName: ";
  cin>>Restau3.Owner.LastName;

  cout<<"Owner's Age: ";
  cin>>Restau3.Owner.Age;

  cout<<"Owner's Phone: ";
  cin>>Restau3.Owner.Phone;

  cout<<"Owner's addresse: ";
  cin>>Restau3.Owner.FounderAdr.City;

  cout<<"Owner's Country: ";
  cin>>Restau3.Owner.FounderAdr.Country;

  cout<<"Restaurant Location: ";
  cin>>Restau3.RestaurantAdr.Location;

  cout<<"Restaurant Name: "<<Restau3.Name<<"\n";
  cout<<"Founded In: "<<Restau3.FoundedIn<<"\n";
  cout<<"Owner's name: "<<Restau3.Owner.FirstName + " " + Restau3.Owner.LastName<<"\n";
  cout<<"Owner's Age: "<<Restau3.Owner.Age<<"\n";
  cout<<"Owner's Phone: "<<Restau3.Owner.Phone<<"\n";
  cout<<"Owner's City: "<<Restau3.Owner.FounderAdr.City<<"\n";
  cout<<"Owner's Country: "<<Restau3.Owner.FounderAdr.Country<<"\n";
  cout<<"Restaurant Location: "<<Restau3.RestaurantAdr.Location<<endl;

  return 0;
}
