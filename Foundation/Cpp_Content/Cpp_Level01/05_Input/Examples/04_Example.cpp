#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  //Initializing Data Containers
  int MyAge{0};
  int AdditionalYears{0};
  int AfterYears{0};

  //Inputs
  cout<<"Enter your age: ";
  cin>>MyAge;

  cout<<"Add years: ";
  cin>>AdditionalYears;

  //Calculation
  AfterYears = MyAge + AdditionalYears;

  //Outputs
  cout<<"After "<<AdditionalYears<<" years you will be "<<AfterYears<<" years old."<<endl;
  return 0;
}
