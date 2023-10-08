#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum enOperationType{Addition = '+', Substraction = '-', Multiplication = '*', Division = '/'};

int main()
{
  enOperationType OperationType;
  short Num1{0}, Num2{0};
  char TypePicker{'+'};

  cout<<"Enter 1st number: ";
  cin>>Num1;

  cout<<"Enter 2nd number: ";
  cin>>Num2;

  cout<<"Choose operation type(+, -, *, /): ";
  cin>>TypePicker;

  OperationType = (enOperationType)TypePicker;

  switch (OperationType) {
  case enOperationType::Addition:
    cout<<Num1 + Num2<<endl;
    break;
  case enOperationType::Substraction:
    cout<<Num1 - Num2<<endl;
    break;
  case enOperationType::Multiplication:
    cout<<Num1 * Num2<<endl;
    break;
  case enOperationType::Division:
    cout<<Num1 / Num2<<endl;
    break;
  default:
    cout<<"Unvalid operation!";
  }
  return 0;
}
