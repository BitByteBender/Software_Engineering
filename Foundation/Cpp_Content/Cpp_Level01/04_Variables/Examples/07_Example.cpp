#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
  string Stars{"**********************************"};
  string FirstName{"Donald"}, MiddleName{"Jhon"}, LastName{"Trump"};
  int Age{65};
  string State{"New York"}, Country{"United States Of America"};
  float MonthlySalary{54000.00f};
  float YearlySalary = MonthlySalary * 12.0f;
  char Gender{'M'};
  bool isMarried{true};

  cout<<Stars<<"\n";
  cout<<"Name: "<<FirstName + " " + MiddleName + " " + LastName<<"\n";
  cout<<"Age: "<<Age<<" years.\n";
  cout<<"State: "<<State<<"\n";
  cout<<"Country: "<<Country<<"\n";
  cout<<"Monthly Salary: $"<<MonthlySalary<<"\n";
  cout<<"Yearly Salary: $"<<YearlySalary<<"\n";
  cout<<"Gender: "<<Gender<<"\n";
  cout<<"Married: "<<isMarried<<"\n";
  cout<<Stars<<endl;
  return 0;
}
