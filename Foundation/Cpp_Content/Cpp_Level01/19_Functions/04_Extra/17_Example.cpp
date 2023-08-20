#include <iostream>

using std::cout;
using std::endl;
using std::cin;

short ReadNumber(std::string Message){
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

short CalculateTheSum(short Number1, short Number2){
  return Number1 + Number2;
}

void PrintSum(short Sum){
  cout<<"The sum is: "<<Sum<<endl;
}

int main()
{
  short Num1 = ReadNumber("Enter 1st number: ");
  short Num2 = ReadNumber("Enter 2nd number: ");
  short Sum = CalculateTheSum(Num1, Num2);
  PrintSum(Sum);
  return 0;
}
