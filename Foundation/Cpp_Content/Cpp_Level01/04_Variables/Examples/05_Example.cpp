#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int HisAge{15}, HerAge, MyAge;
  HerAge = HisAge;
  MyAge = HerAge;

  cout<<"Her age: "<<HerAge<<"\nMy Age: "<<MyAge<<"\nHis Age: "<<HisAge<<"\n";

  int Num1{78}, Num2 = Num1 + 2, Num3 = Num2 + 20;
  cout<<"Num1 = "<<Num1<<"\nNum2 = "<<Num2<<"\nNum3 = "<<Num3<<endl;
  return 0;
}
