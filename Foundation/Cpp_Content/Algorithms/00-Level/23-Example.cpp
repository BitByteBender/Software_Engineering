#include <iostream>

using std::cout;
using std::endl;
using std::cin;

short ReadNumber(std::string Message)
{
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

void SwapNumbers(short &Num1, short &Num2)
{
  short TempVar{0};
  TempVar = Num1;
  Num1 = Num2;
  Num2 = TempVar;
}

void PrintSwappedNums(short Num1, short Num2)
{
  cout<<"Num1: "<<Num1<<"\n";
  cout<<"Num2: "<<Num2<<"\n\n";
  
  SwapNumbers(Num1, Num2);
  cout<<"Num1: "<<Num1<<"\n";
  cout<<"Num2: "<<Num2<<endl;
}

int main()
{
  short Num1{0}, Num2{0};

  Num1 = ReadNumber("Ener num1: ");
  Num2 = ReadNumber("Enter num2: ");
  PrintSwappedNums(Num1, Num2);
  return 0;
}
