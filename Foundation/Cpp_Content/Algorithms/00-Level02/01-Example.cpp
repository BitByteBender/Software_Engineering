#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum enPrimeNotPrime{NotPrime = 0, Prime = 1};

short ReadNumber(string Message)
{
  short Num{0};

  
  cout<<Message;
  cin>>Num;

  return (Num);
}

enPrimeNotPrime CheckPrimeORNot(short Num)
{
  short i, Number = round(Num / 2);

  for (i = 2; i <= Number; i++) {
    if (Num % i == 0) {
      return enPrimeNotPrime::NotPrime;
    }
  }

  return (enPrimeNotPrime::Prime);
}

void PrintPrimeOrNotPrime(short Num)
{
  short i;
  
  for (i = 1; i <= Num; i++) {
    
    if (i <= 2)
    {
      cout<<i<<"\n";
      continue;
    }
    else
    {
      if (CheckPrimeORNot(i))
      {
	cout<<i<<endl;
      }
    }
    
  }
  
  cout<<endl;
}

int main()
{
  short Num = ReadNumber("Enter a number: ");
  PrintPrimeOrNotPrime(Num);
  return 0;
}
