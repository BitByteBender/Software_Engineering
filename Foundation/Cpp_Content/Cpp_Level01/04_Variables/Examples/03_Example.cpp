#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
  float Salary{7850.25f};
  cout<<"My Salary is: $"<<Salary<<"\n";
  int Multiplier{12};
  float yearlySalary = Salary * Multiplier;
  cout<<"My yearlySalary is: $"<<yearlySalary<<endl;
  return 0;
}
