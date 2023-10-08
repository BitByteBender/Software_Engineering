#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short Num1{0}, Num2{0};
  char TypePicker{'+'};

  cout<<"Enter 1st number: ";
  cin>>Num1;

  cout<<"Enter 2nd number: ";
  cin>>Num2;

  cout<<"Choose operation type(+, -, *, /): ";
  cin>>TypePicker;


  switch (TypePicker) {
  case '*':
    cout<<Num1 * Num2<<endl;
    break;
  case '/':
    cout<<Num1 / Num2<<endl;
    break;
  case '+':
    cout<<Num1 + Num2<<endl;
    break;
  case '-':
    cout<<Num1 - Num2<<endl;
    break;
  default:
    cout<<"Unvalid operation!";
  }
  return 0;
}
