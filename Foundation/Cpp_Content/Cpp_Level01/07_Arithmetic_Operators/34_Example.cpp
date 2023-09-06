#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Pennies{0}, Nickels{0}, Dimes{0}, Quarters{0};
  float Dollars{0.0f};
  unsigned short TotalInPennies{0};
  float TotalInDollars{0.0f};
  
  cout<<"How many Pennies: ";
  cin>>Pennies;

  cout<<"How many Nickels: ";
  cin>>Nickels;

  cout<<"How many Dimes: ";
  cin>>Dimes;

  cout<<"How many Quarters: ";
  cin>>Quarters;

  cout<<"How many Dollars: ";
  cin>>Dollars;

  TotalInPennies = Pennies + (Nickels * 5) + (Dimes * 10) + (Quarters * 25) + (Dollars * 100);
  TotalInDollars = TotalInPennies / 100.0f;

  cout<<TotalInPennies<<" Pennies\n";
  cout<<TotalInDollars<<" Dollars"<<endl;
  return 0;
}
