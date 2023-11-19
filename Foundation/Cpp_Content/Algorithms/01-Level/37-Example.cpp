#include <iostream>
#include <ctime>

using std::cout, std::cin;
using std::endl;
using std::string;

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

void AddArrayElements(unsigned short Number, unsigned short Arr[100], unsigned short &Length)
{
  Length++;
  Arr[Length - 1] = Number;
}

void CopyOddArrayNumbers(unsigned short ArrSrc[100], unsigned short ArrDest[100], unsigned short SrcLength, unsigned short &DestLength)
{
  unsigned short i = 0;

  for (i = 0; i <= (SrcLength - 1); i++) {
    if (ArrSrc[i] % 2 != 0) {
      AddArrayElements(ArrSrc[i], ArrDest, DestLength);
      }
  }
}

int main(void)
{

  srand((unsigned)time(nullptr));

  unsigned short ArrSrc[100], SrcLength = 0;
  unsigned short ArrDest[100], DestLength = 0;

  SrcLength = ReadPositiveNumber("How many elements: ");

  FillArray(ArrSrc, SrcLength);

  PrintArrayElements(ArrSrc, SrcLength, "Array 1 elements:\n");

  CopyOddArrayNumbers(ArrSrc, ArrDest, SrcLength, DestLength);

  PrintArrayElements(ArrDest, DestLength, "Array 2 Odd numbers:\n");
  return (0);
}
