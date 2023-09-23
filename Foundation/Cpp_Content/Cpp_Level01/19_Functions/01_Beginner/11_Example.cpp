#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int MySumFunc(){

  short Num1{0}, Num2{0};

  cout<<"Enter 1st number: ";
  cin>>Num1;

  cout<<"Enter 2nd number: ";
  cin>>Num2;

  return Num1 + Num2;
}

int main()
{
  cout<<"\n********************\n"<<MySumFunc()<<endl;
  return 0;
}
