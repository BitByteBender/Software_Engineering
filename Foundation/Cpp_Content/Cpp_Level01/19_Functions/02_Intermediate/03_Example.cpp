#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int MySumFunction(){
  int Number1, Number2, Sum{0};
  cout<<"Enter number1: ";
  cin>>Number1;

  cout<<"Enter number2: ";
  cin>>Number2;

  Sum = Number1 + Number2;
  return Sum;
}

int main()
{
  cout<<MySumFunction()<<"\n";
  return 0;
}
