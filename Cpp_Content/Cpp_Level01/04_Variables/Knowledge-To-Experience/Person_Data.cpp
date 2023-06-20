#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
  string Stars = "*******************************";
  cout<<Stars<<"\n";

  string Name{"Soufiane Sadgali"};
  cout<<"Name: "<<Name<<"\n";

  short Age{29};
  cout<<"Age: "<<Age<<"\n";

  string City{"Bouznika"}, Country{"Morocco"};
  cout<<"City: "<<City<<"\n";
  cout<<"Country: "<<Country<<"\n";

  const unsigned short Months{12};
  unsigned short MonthlySalary = 6500;
  cout<<"Monthly Salary: "<<MonthlySalary<<" USD\n";
  
  unsigned int YearlySalary = Months * MonthlySalary;
  cout<<"YearlySalary: "<<YearlySalary<<" USD\n";

  char Gender{'M'};
  cout<<"Gender: "<<Gender<<"\n";

  bool Married{false};
  cout<<"Married: "<<Married<<"\n";
  
  cout<<Stars<<endl;
  return 0;
}
