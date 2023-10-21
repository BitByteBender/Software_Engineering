#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct stNumbers
{
  unsigned short Num1, Num2, Num3;
};

short ReadNumber(std::string Message)
{
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

void ReadNumbers(stNumbers &Nums)
{
  Nums.Num1 = ReadNumber("Enter num1: ");
  Nums.Num2 = ReadNumber("Enter num2: ");
  Nums.Num3 = ReadNumber("Enter num3: ");
}

short SumOfNumbers(stNumbers Nums)
{
  short Sum = 0;
  return Sum = (Nums.Num1 + Nums.Num2 + Nums.Num3);
}

void PrintSum(stNumbers Nums)
{
  cout<<"Sum: "<<SumOfNumbers(Nums)<<endl;
}

int main()
{
  stNumbers Nums;
  ReadNumbers(Nums);
  PrintSum(Nums);
  return 0;
}
