#include <iostream>

using std::cout;
using std::endl;

short ReadNumbers(){

  short Num{0};

  cout<<"Enter a number: ";
  std::cin>>Num;

  return Num;
}

void SwapFunc(short &Num1, short &Num2){
  
  short TempVarHolder = Num1;
  
  Num1 = Num2;
  Num2 = TempVarHolder;

}

void PrintSwappedAndNonSwappedNumbers(short Num1, short Num2){

  cout<<"Original: "<<Num1<<" "<<Num2<<"\n";
  SwapFunc(Num1, Num2);
  cout<<"Swapped: "<<Num1<<" "<<Num2<<endl;

}

int main()
{
  short Num1 = ReadNumbers();
  short Num2 = ReadNumbers();
  PrintSwappedAndNonSwappedNumbers(Num1, Num2);
  return 0;
}

