#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  float Pennies{0.0f}, Nickels{0.0f}, Dimes{0.0f}, Quarters{0.0f}, Dollars{0.0f};

  cout<<"How many Pennies? ";
  cin>>Pennies;

  cout<<"How many Nickels? ";
  cin>>Nickels;

  cout<<"How many Dimes? ";
  cin>>Dimes;

  cout<<"How many Quarters? ";
  cin>>Quarters;

  cout<<"How many Dollars? ";
  cin>>Dollars;

  unsigned int TotalPennies = (Pennies * 1) + (Nickels * 5) + (Dimes * 10) + (Quarters * 25) + (Dollars * 100);

  float PenniesToDollars = TotalPennies / 100.0f;
  
  cout<<TotalPennies<<" Pennies\n";
  cout<<PenniesToDollars<<" Dollars"<<endl;
  return 0;
}
