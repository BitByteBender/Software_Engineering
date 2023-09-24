#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void SwapNumbers(short &Num1, short &Num2){
  short TempVar = Num1;
  Num1 = Num2;
  Num2 = TempVar;
}

void PrintResult(short Num1, short Num2){
  cout<<"Num1: "<<Num1<<" /*\\ Num2: "<<Num2<<"\n";
  SwapNumbers(Num1, Num2);
  cout<<"Num1: "<<Num1<<" /*\\ Num2: "<<Num2<<endl;
}

int main()
{
  short Num1{15}, Num2{2};
  PrintResult(Num1, Num2);
  return 0;
}
