#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short Num1{0}, Num2{0}, Num3{0};
  short Sum{0};

  cout<<"Enter num1: ";
  cin>>Num1;

  cout<<"Enter num2: ";
  cin>>Num2;

  cout<<"Enter num3: ";
  cin>>Num3;

  Sum = Num1 + Num2 + Num3;

  cout<<Sum<<endl;
  return 0;
}
