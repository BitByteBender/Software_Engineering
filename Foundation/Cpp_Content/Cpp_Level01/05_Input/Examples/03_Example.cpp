#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  //Initializing Identifiers
  std::string Style{"-------------------------------------"};
  int FirstNumber{0}, SecondNumber{0}, ThirdNumber{0}, FourthNumber{0};
  int Sum{0};

  //Inputs
  cout<<"Enter 1st number: ";
  cin>>FirstNumber;

  cout<<"Enter 2nd number: ";
  cin>>SecondNumber;

  cout<<"Enter 3rd number: ";
  cin>>ThirdNumber;

  cout<<"Enter 4th number: ";
  cin>>FourthNumber;

  //Calculation
  Sum = FirstNumber + SecondNumber + ThirdNumber + FourthNumber;

  //Outputs
  cout<<FirstNumber<<" +\n";
  cout<<SecondNumber<<" +\n";
  cout<<ThirdNumber<<" +\n";
  cout<<FourthNumber<<"\n";
  cout<<Style<<"\n";
  cout<<"Total =  "<<Sum<<endl;
  return 0;
}
