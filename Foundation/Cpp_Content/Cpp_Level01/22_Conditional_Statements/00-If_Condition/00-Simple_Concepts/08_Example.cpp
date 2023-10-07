#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  short Num1{0}, Num2{0};
  char OperationType{'+'};

  cout<<"Enter num1: ";
  cin>>Num1;

  cout<<"Enter num2: ";
  cin>>Num2;

  cout<<"What's type of operation you want?(+, -, *, /): ";
  cin>>OperationType;

  if (OperationType == '+') {
    cout<<Num1 + Num2<<endl;
  }else if(OperationType == '-'){
    cout<<Num1 - Num2<<endl;
  }else if(OperationType == '*'){
    cout<<Num1 * Num2<<endl;
  }else {
    cout<<float(Num1 / Num2)<<endl;
  }
  return 0;
}
