#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  short Num1{0}, Num2{0};
  short Temp{0};

  cout<<"Enter num1: ";
  cin>>Num1;

  cout<<"Enter num2: ";
  cin>>Num2;

  cout<<"Num1: "<<Num1<<" | Num2: "<<Num2<<"\n";
  
  Temp = Num1;
  Num1 = Num2;
  Num2 = Temp;

  cout<<"Num1: "<<Num1<<" | Num2: "<<Num2<<endl;
  return 0;
}
