#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum enCountries{Morocco = 1, South_Africa = 2, Ghana = 3, Nigeria = 4, Other = 5};

int main()
{
  enCountries Country;
  short Picker{0};

  cout<<"Pick a country:\n"
      <<"1/ Morocco\n"
      <<"2/ South Africa\n"
      <<"3/ Ghana\n"
      <<"4/ Nigeria\n"
      <<"Your Pick? ";
  cin>>Picker;

  Country = (enCountries) Picker;

  cout<<"You have picked up "<<Picker<<" which is ";
  switch (Country)
  {
  case enCountries::Morocco:
    cout<<"Morocco"<<endl;
    break;
  case enCountries::South_Africa:
    cout<<"South Africa"<<endl;
    break;
  case enCountries::Ghana:
    cout<<"Ghana"<<endl;
    break;
  case enCountries::Nigeria:
    cout<<"Nigeria"<<endl;
    break;
  default:
    cout<<"Other"<<endl;
  }
  return 0;
}
