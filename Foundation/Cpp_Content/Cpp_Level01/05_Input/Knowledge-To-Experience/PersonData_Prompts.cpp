#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  //Prompts
  cout<<"Enter a bunch of stars: ";
  string Stars{"Empty"};
  cin>>Stars;
  

  cout<<"What's your full name?: ";
  string Fullname{"Empty"};
  cin>>Fullname;

  cout<<"How old are you?: ";
  int Age{0};
  cin>>Age;
  

  cout<<"Enter your city of birth?: ";
  string BirthCity{"Empty"}, Country{"Empty"};
  cin>>BirthCity;
  

  cout<<"Which country are you from?: ";
  cin>>Country;
  

  cout<<"How much do you get paid monthly?: ";
  float MonthlySalary{0.0f};
  cin>>MonthlySalary;
 

  const int Months{12};
  float YearlySalary{MonthlySalary * Months};
 

  cout<<"Enter your gender?: (M: Male|F: Female)";
  char Gender{'M'};
  cin>>Gender;
  

  cout<<"Are you married?: (Yes: 1| No: 0)";
  bool isMarried{false};
  cin>>isMarried;
  
  //Printing the card
  cout<<Stars<<"\n";
  cout<<"Name: "<<Fullname<<"\n";
  cout<<"Age: "<<Age<<"\n";
  cout<<"City: "<<BirthCity<<"\n";
  cout<<"Country: "<<Country<<"\n";
  cout<<"Monthly Salary: "<<MonthlySalary<<" USD\n";
  cout<<"Yearly Salary: "<<YearlySalary<<" USD\n";
  cout<<"Gender: "<<Gender<<"\n";
  cout<<"Married: "<<isMarried<<"\n";
  cout<<Stars<<endl;
  
  return 0;
}
