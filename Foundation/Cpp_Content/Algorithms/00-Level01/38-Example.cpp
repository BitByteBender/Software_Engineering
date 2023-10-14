#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadPositiveNumber(string Message)
{
  short Num{0};
  cout<<Message;
  
  do {
    cin>>Num;
    
    if (Num > 0) {
      break;
    }
    else
    {
      cout<<"Enter a positive number: ";
    }
  } while (Num <= 0);
  
  return Num;
}

void ReadN(short &N)
{
  N = ReadPositiveNumber("Enter N: ");
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
