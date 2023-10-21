#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadNumber(string Message)
{
  short Num{0};

  cout<<Message;
  cin>>Num;

  return Num;
}

void ReadN(short &N)
{
  N = ReadNumber("Enter N: ");
}

bool checkEvenNumbers(short N)
{
  return (N % 2 == 0 ? 1 : 0);
}

short SumEvenNumbers(short N)
{
  unsigned short i, Sum{0};
  
  for (i = N; i >= 1; i--)
  {
    if (checkEvenNumbers(i))
    {
      Sum = Sum + i;
    }
  }
  
  return Sum;
}

void PrintSum(short Sum)
{
  cout<<"Sum: "<<SumEvenNumbers(Sum)<<endl;
}

int main()
{
  short N{0};

  ReadN(N);
  PrintSum(N);
  return 0;
}
