#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout<<"How old are you?: ";
  int Age{0};
  cin>>Age;

  cout<<"Enter a number to check your age after a number of years?: ";
  int AfterYears{0};
  cin>>AfterYears;

  cout<<"After "<<AfterYears<<" years you will be "<<Age + AfterYears<<" years old."<<endl;
  return 0;
}
