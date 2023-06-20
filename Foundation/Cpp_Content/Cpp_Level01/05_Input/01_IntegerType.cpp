#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout<<"Enter your age: ";
  int Age{0};//Always initialize your variables
  cin>>Age;
  cout<<"Your Age is: "<<Age<<endl;

  cout<<"Enter a firstnumber: ";
  int Firstnumber{0};
  cin>>Firstnumber;

  cout<<"Enter a secondnumber: ";
  int Secondnumber{0};
  cin>>Secondnumber;

  cout<<"Enter a thirdnumber: ";
  int Thirdnumber{0};
  cin>>Thirdnumber;

  //Ex: 10 + 11 + 12
  int Total = Firstnumber + Secondnumber + Thirdnumber;
  cout<<"The Total is: "<<Total<<endl;//Output: 33
  return 0;
}
