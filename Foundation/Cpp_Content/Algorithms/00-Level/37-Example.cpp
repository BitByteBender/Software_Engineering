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

short CalculateFactorial(short N)
{
  unsigned short i, Product{1};
  
  for (i = N; i >= 1; i--)
  {
    
     Product = Product * i;
  }
  
  return Product;
}

void PrintFactorialOfN(short Product)
{
  cout<<"Factorial Of N: "<<CalculateFactorial(Product)<<endl;
}

int main()
{
  short N{0};

  ReadN(N);
  PrintFactorialOfN(N);
  return 0;
}
