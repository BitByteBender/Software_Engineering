#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;

/**
 * Enter a number: 20
 * Array 1 elements: 17 46 31 76 96 88 66 9 40 6 39 62 33 96 15 83 23 33 98 4
 * Copied Array elements: 17 46 31 76 96 88 66 9 40 6 39 62 33 96 15 83 23 33 98 4
 * Prime numbers in Copied Array: 17 31 83 23 
 * ==91531== 
 * ==91531== HEAP SUMMARY:
 * ==91531==     in use at exit: 0 bytes in 0 blocks
 * ==91531==   total heap usage: 7 allocs, 7 frees, 74,855 bytes allocated
 * ==91531== 
 * ==91531== All heap blocks were freed -- no leaks are possible
 * ==91531== 
 * ==91531== For lists of detected and suppressed errors, rerun with: -s
 * ==91531== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

enum enPrimeOrNot{Prime = 0, NotPrime = 1};

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

void FillArray(uint16_t *&Arr, uint16_t Length)
{
  uint16_t i = 0;
  Arr = (uint16_t *)malloc(sizeof(uint16_t) * (Length + 1));

  for (i = 0; i <= (Length - 1); i++) {
    Arr[i] = Randomizer(1, 100);
  }

  Arr[Length] = '\0';
}

uint16_t *CopiedArray(uint16_t *Arr, uint16_t Length)
{
  uint16_t i = 0, *NewArr = (uint16_t *)malloc(sizeof(uint16_t) * (Length + 1));

  for (i = 0; i <= (Length - 1); i++) {
    NewArr[i] = Arr[i];
  }

  NewArr[Length] = '\0';

  return (NewArr);
}

void PrintArrayElements(const uint16_t *Arr, const uint16_t Length, char SmallNum)
{
  cout<<"Array "<<SmallNum<<" elements: ";
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

enPrimeOrNot isPrime(uint16_t *Arr)
{
  uint16_t i = 0, RoundNum = round(*Arr / 2); 

  for (i = 2; i <= RoundNum; i++) {
    if (*Arr % i == 0) {
      return (enPrimeOrNot::NotPrime);
    }
  }
  
  return (enPrimeOrNot::Prime);
}

void PrintPrimeNums(uint16_t *CopiedArr, uint16_t Length)
{
  uint16_t i = 0;

  cout<<"Prime numbers in array CopiedArr: ";

  for (i = 0; i <= (Length - 1); i++) {
    if (isPrime(&CopiedArr[i]) == enPrimeOrNot::Prime) {
      cout<<CopiedArr[i]<<' ';
    }
  }
  cout<<endl;
}

void FreeAllocMemo(uint16_t* Arr, uint16_t* CopiedArr, uint16_t *ptrNum)
{
  free(ptrNum);
  free(Arr);
  free(CopiedArr);
}

int main()
{
  srand((unsigned)time(nullptr));
	
  uint16_t *Length = ReadPositiveNumber("Enter a number: ");
  uint16_t *Arr = nullptr, *CopiedArr = nullptr;
  
  FillArray(Arr, *Length);
  PrintArrayElements(Arr, *Length, '1');

  CopiedArr = CopiedArray(Arr, *Length);
  PrintArrayElements(CopiedArr, *Length, '2');
  PrintPrimeNums(CopiedArr, *Length);
  
  FreeAllocMemo(Arr, CopiedArr, Length);
  return 0;
}
