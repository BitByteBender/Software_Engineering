#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum enCountries{Morocco = 1, Spain = 2, Portugal = 3};

int main()
{
  enCountries Country;
  short Picker{0};

  cout<<"Choose a country:\n"
      <<"(1) Morocco\n"
      <<"(2) Spain\n"
      <<"(3) Portugal\n";
  cin>>Picker;

  Country = (enCountries)Picker;

  cout<<"You have picked: "<<Picker<<"\nCountry: ---> ";
  
  if (Country == enCountries::Morocco){
    cout<<"Morocco"<<endl;
  }else if(Country == enCountries::Spain){
    cout<<"Spain"<<endl;
  }else if(Country == enCountries::Portugal){
    cout<<"Portugal"<<endl;
  }else{
    cout<<"It's doesnt exist on our list!"<<endl;
  }
  
  return 0;
}
