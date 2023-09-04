#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  //Initializing variables
  string Card{"Empty"};
  string FirstName{"Empty"}, MiddleName{"Empty"}, LastName{"Empty"};
  int Age{0};
  string City{"Empty"}, Country{"Empty"};
  float MonthlySalary{0.0f};
  char Gender{'M'};
  bool isMarried{false};

  //Inputs: Calling variables to store Data
  cout<<"Enter a card style: ";
  cin>>Card;

  cout<<"Enter a firstname: ";
  cin>>FirstName;

  cout<<"Enter a middlename: ";
  cin>>MiddleName;

  cout<<"Enter a lastname: ";
  cin>>LastName;

  cout<<"How old are you?: ";
  cin>>Age;

  cout<<"Enter a city: ";
  cin>>City;

  cout<<"Enter a country: ";
  cin>>Country;

  cout<<"What's your monthly earning?: ";
  cin>>MonthlySalary;

  cout<<"Are you a male or female?: ";
  cin>>Gender;

  cout<<"Are you married?(0/1): ";
  cin>>isMarried;

  //Calculation
  float YearlySalary{MonthlySalary * 12.0f};
  
  //Outputs: retrieving stored Data
  cout<<Card<<"\n";
  cout<<"Name: "<<FirstName + " " + MiddleName + " " + LastName<<"\n";
  cout<<"Age: "<<Age<<"\n";
  cout<<"City: "<<City<<"\n";
  cout<<"Country: "<<Country<<"\n";
  cout<<"Monthly Salary: "<<MonthlySalary<<"\n";
  cout<<"Yearly Salary: "<<YearlySalary<<"\n";
  cout<<"Gender: "<<Gender<<"\n";
  cout<<"Married: "<<isMarried<<"\n";
  cout<<Card<<endl;
  
  return 0;
}
