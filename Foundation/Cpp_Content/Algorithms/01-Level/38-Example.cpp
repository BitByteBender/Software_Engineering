#include <iostream>
#include <ctime>
#include <cmath>

using std::cout, std::cin;
using std::endl;
using std::string;

enum enPrimeOrNot
{
  NotPrime = 0,
  Prime = 1
};

unsigned short ReadPositiveNumber(string Message)
{
  unsigned short Num{0};
  
  do {
    cout<<Message;
    cin>>Num;
  } while (Num <= 0);

  return (Num);
}

inline unsigned short RandomizeNumbers(unsigned short From, unsigned short To)
{
  return (rand() % (To - From + 1) + From);
}

void FillArray(unsigned short Arr[100], unsigned short &Length)
{
  unsigned short i = 0;

  for (i = 0; i <= (Length - 1); i++) {
    Arr[i] = RandomizeNumbers(1, 100);
  }
  
}

void PrintArrayElements(const unsigned short Arr[100], const unsigned short Length, const char *Message)
{
  unsigned short i = 0;
  
  cout<<Message;
  
  for (i = 0; i <= (Length - 1); i++) {
    if (i == (Length - 1)) {
      cout<<Arr[i];
    }
    else
    {
      cout<<Arr[i]<<" ";
    }
  }

  cout<<endl;
}

enPrimeOrNot checkPrime(unsigned short Number)
{
  unsigned short i = 0, reducNum= round(Number / 2);

  for (i = 2; i <= (reducNum); i++) {
    if (Number % i == 0) {
      return (enPrimeOrNot::NotPrime);
    }
  }

  return (enPrimeOrNot::Prime);
}

void AddArrayElements(unsigned short Number, unsigned short Arr[100], unsigned short &Length)
{
  Arr[Length] = Number;
  Length++;
}

void CopyPrimeNumbers(unsigned short ArrSrc[100], unsigned short ArrDest[100], unsigned short SrcLength, unsigned short &DestLength)
{
  unsigned short i = 0;
  
  for (i = 0; i <= (SrcLength - 1); i++) {
    if (checkPrime(ArrSrc[i])) {
      AddArrayElements(ArrSrc[i], ArrDest, DestLength);
    }
  }
}

int main(void)
{

  srand((unsigned)time(nullptr));

  unsigned short ArrSrc[100], SrcLength{0}, DestLength{0};
  unsigned short ArrDest[100];

  SrcLength = ReadPositiveNumber("How many elements: ");

  FillArray(ArrSrc, SrcLength);

  PrintArrayElements(ArrSrc, SrcLength, "Array 1 elements:\n");

  CopyPrimeNumbers(ArrSrc, ArrDest, SrcLength, DestLength);

  PrintArrayElements(ArrDest, DestLength, "Array 2 Odd numbers:\n");
  return (0);
}
