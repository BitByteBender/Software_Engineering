#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout<<"How old are you?: ";
  unsigned short Age{0};
  cin>>Age;

  cout<<"Enter a number to calculate your future age: ";
  unsigned short AfterYears{0};
  cin>>AfterYears;
  
  unsigned short FutureAge = AfterYears + Age;
  
  //Output
  cout<<"After "<<AfterYears<<" years you will be "<<FutureAge<<" years old."<<endl;
  return 0;
}
