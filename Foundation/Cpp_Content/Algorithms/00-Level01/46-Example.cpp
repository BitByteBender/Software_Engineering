#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadNumbers(string Message)
{
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

short SumNumbers(short Num)
{

  int Sum = 0;
  
  while (Num != -99) {
    Sum = Sum + Num;
    Num = ReadNumbers("Re-enter a number: ");
  }
  
  return Sum;
 
}

void PrintSum(short Sum)
{
  cout<<"Total: "<<Sum<<endl;
}

int main()
{
  short Num = ReadNumbers("Enter a number: ");
  PrintSum(SumNumbers(Num));
  return 0;
}
