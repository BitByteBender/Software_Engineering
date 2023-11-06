#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;

/**
 * Enter the length of the array: 10
 * Array 1 elements: 86 70 11 90 27 49 48 30 2 72
 * Array 2 elements: 74 29 76 87 3 77 7 11 20 28
 * Sum of first array and second array elements:
 * 160 99 87 177 30 126 55 41 22 100
 * ==92832== 
 * ==92832== HEAP SUMMARY:
 * ==92832==     in use at exit: 22 bytes in 1 blocks
 * ==92832==   total heap usage: 8 allocs, 7 frees, 74,852 bytes allocated
 * ==92832== 
 * ==92832== LEAK SUMMARY:
 * ==92832==    definitely lost: 22 bytes in 1 blocks
 * ==92832==    indirectly lost: 0 bytes in 0 blocks
 * ==92832==      possibly lost: 0 bytes in 0 blocks
 * ==92832==    still reachable: 0 bytes in 0 blocks
 * ==92832==         suppressed: 0 bytes in 0 blocks
 * ==92832== Rerun with --leak-check=full to see details of leaked memory
 * ==92832== 
 * ==92832== For lists of detected and suppressed errors, rerun with: -s
 * ==92832== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

uint16_t *ReadPositiveNumber(string Message)
{
  uint16_t *ptrNum = (uint16_t *)malloc(sizeof(uint16_t));

  do {
    cout<<Message;
    cin>>*ptrNum;
  } while (*ptrNum <= 0);

  return (ptrNum);
}

uint16_t Randomizer(uint16_t From, uint16_t To)
{
  uint16_t RandNum = (rand() % (To - From + 1) + From);
  return (RandNum);
}

void FillFirstArray(uint16_t *&FirstArr, uint16_t Length)
{
  uint16_t i = 0;
  FirstArr = (uint16_t *)malloc(sizeof(uint16_t) * (Length + 1));

  for (i = 0; i <= (Length - 1); i++) {
    FirstArr[i] = Randomizer(1, 100);
  }

  FirstArr[Length] = '\0';
}

void FillSecondArray(uint16_t *&SecondArr, uint16_t Length)
{
  uint16_t i = 0;
  SecondArr = (uint16_t *)malloc(sizeof(uint16_t) * (Length + 1));

  for (i = 0; i <= (Length - 1); i++) {
    SecondArr[i] = Randomizer(1, 100);
  }

  SecondArr[Length] = '\0';
}

uint16_t *SumNewArray(uint16_t *FirstArr, uint16_t *SecondArr, uint16_t Length)
{
  uint16_t i = 0, Sum = 0, *NewArr = (uint16_t *)malloc(sizeof(uint16_t) * (Length + 1));

  for (i = 0; i <= (Length - 1); i++) {
    Sum = FirstArr[i] + SecondArr[i];
    NewArr[i] = Sum;
  }

  NewArr[Length] = '\0';

  return (NewArr);
}

void PrintArrayElements(const char *Text, const uint16_t *Arr, const uint16_t Length)
{
  cout<<Text;
  uint16_t i = 0;
  
  for (i = 0; i <= (Length - 1); i++) {
    if (i < (Length - 1)) {
      cout<<Arr[i]<<" ";
    }
    else {
      cout<<Arr[i]<<endl;
    }
  }
}

void FreeAllocMemo(uint16_t* FirstArr, uint16_t* SecondArr, uint16_t* SumArr, uint16_t *ptrNum)
{
  free(ptrNum);
  free(FirstArr);
  free(SecondArr);
  free(SumArr);
}

int main()
{
  srand((unsigned)time(nullptr));
	
  uint16_t *Length = ReadPositiveNumber("Enter the length of the array: ");
  uint16_t *FirstArr = nullptr, *SecondArr = nullptr, *SumArr = nullptr;
  
  FillFirstArray(FirstArr, *Length);
  PrintArrayElements(("\nArray 1 elements: "), FirstArr, *Length);

  FillSecondArray(SecondArr, *Length);
  PrintArrayElements(("\nArray 2 elements: "), SecondArr, *Length);

  SumArr = SumNewArray(FirstArr, SecondArr, *Length);
  PrintArrayElements("\nSum of first array and second array elements:\n", SumArr, *Length);
  
  FreeAllocMemo(Length, FirstArr, SecondArr, SumArr);
  return (0);
}
