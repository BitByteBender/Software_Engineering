#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

/**
 * Enter the length of the array: 10
 * Array 1 Elements:
 * 5 81 65 18 86 55 81 29 36 3
 * Array 2 elements after a reversed copy:
 * 3 36 29 81 55 86 18 65 81 5
 * ==114019== 
 * ==114019== HEAP SUMMARY:
 * ==114019==     in use at exit: 0 bytes in 0 blocks
 * ==114019==   total heap usage: 6 allocs, 6 frees, 74,798 bytes allocated
 * ==114019== 
 * ==114019== All heap blocks were freed -- no leaks are possible
 * ==114019== 
 * ==114019== For lists of detected and suppressed errors, rerun with: -s
 * ==114019== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */
short *ReadPositiveNumber(const char *Message)
{
  short *ptrNumber = (short *)malloc(sizeof(short));

  do {
    cout<<Message;
    cin>>*ptrNumber;
  } while (*ptrNumber <= 0);

  return (ptrNumber);
}

short Randomizer(short From, short  To)
{
  short RandNum = (rand() % (To - From + 1) + From);
  return (RandNum);
}

void ArrayFiller(short *&Arr, short Length)
{
  uint16_t i = 0;

  Arr = (short *)malloc(sizeof(short) * (Length + 1));

  for (i = 0; i <= (Length - 1); i++) {
    Arr[i] = Randomizer(1, 100);
  }

  Arr[Length] = 0;
}

short *ReverseArray(short *Arr, short Length)
{
  short i = 0, *ReversedArray = (short *)malloc(sizeof(short) * (Length + 1));

  for (i = 0; i <= (Length - 1); i++) {
    ReversedArray[(Length - 1) - i] = Arr[i];
  }

  ReversedArray[Length] = 0;

  return (ReversedArray);
}

void PrintArrayElements(const char *Text, const short *Arr, const short Length)
{
  uint16_t i = 0;

  cout<<Text;
  
  for (i = 0; i <= (Length - 1); i++) {
    if (i < (Length - 1)) {
      cout<<Arr[i]<<" ";
    }
    else
    {
      cout<<Arr[i]<<endl;
    }
  }
}

void FreeMemoAlloc(short *ptrNumber, short *Arr, short *ReverseArray)
{
  free(ReverseArray);
  free(Arr);
  free(ptrNumber);
}

int main(void)
{
  srand((unsigned)time(NULL));
  short *Length = ReadPositiveNumber("Enter the length of the array: ");
  short *Arr = nullptr, *RArr = nullptr;

  ArrayFiller(Arr, *Length);
  PrintArrayElements("Array 1 Elements:\n", Arr, *Length);
  
  RArr = ReverseArray(Arr, *Length);
  PrintArrayElements("\nArray 2 elements after a reversed copy:\n", RArr, *Length);
  
  FreeMemoAlloc(Length, Arr, RArr);
  return (0);
}
