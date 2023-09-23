#include <iostream>

using std::cout;
using std::endl;
using std::cin;

short ReadNumbers(){

  short Num{0};

  cout<<"Enter number: ";
  cin>>Num;

  return Num;
  
}

short CalculateSum(short Num1, short Num2){
  short Sum = Num1 + Num2;
  return Sum;
}

void PrintSum(short Sum){

  cout<<"Sum: "<<Sum<<"\n";
}

int main()
{
  short Num1 = ReadNumbers();
  short Num2 = ReadNumbers();
  PrintSum(CalculateSum(Num1, Num2));
  return 0;
}

