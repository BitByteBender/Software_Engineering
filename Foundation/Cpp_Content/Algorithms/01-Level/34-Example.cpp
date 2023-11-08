#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

/**
 * Enter array length: 10
 * Array 1 elements: 85 27 83 83 4 90 45 54 87 45
 * What's the number you want to search?
 * -> 85
 * Number your are looking for is: 85
 * Yes, The number has been found :-)
 * ==121747== 
 * ==121747== HEAP SUMMARY:
 * ==121747==     in use at exit: 0 bytes in 0 blocks
 * ==121747==   total heap usage: 16 allocs, 16 frees, 74,798 bytes allocated
 * ==121747== 
 * ==121747== All heap blocks were freed -- no leaks are possible
 * ==121747== 
 * ==121747== For lists of detected and suppressed errors, rerun with: -s
 * ==121747== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

uint16_t *ReadPositiveNumber(const char *Message)
{
  uint16_t *ptrNum = new uint16_t(sizeof(uint16_t *));

  do {
    cout<<Message;
    cin>>*ptrNum;
    
  } while (*ptrNum <= 0);

  return (ptrNum);
}

uint16_t *GetRandomNumber(uint16_t From, uint16_t To)
{
  uint16_t *ptrRandomized = new uint16_t;

  *ptrRandomized = (rand() % (To - From + 1) + From);

  return (ptrRandomized);
}

void GenerateArray(uint16_t *&Arr, uint16_t Length)
{
  uint16_t i = 0, *RandNum = nullptr;

  Arr = new uint16_t[Length + 1];
  
  for (i = 0; i <= (Length - 1); i++) {
    RandNum = GetRandomNumber(1, 100);
    Arr[i] = *RandNum;

    delete (RandNum);
  }

  Arr[Length] = 0;
}

void PrintGeneratedArray(const uint16_t *Arr, const uint16_t Length)
{
  cout<<"Array 1 elements: ";

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

bool CheckNumberPosition(const uint16_t *Arr, const uint16_t Length, const uint16_t Number)
{
  cout<<"Number your are looking for is: "<<Number<<"\n";

  uint16_t i = 0;

  for (i = 0; i <= (Length - 1); i++) {
    if (Arr[i] == Number ) {
      return (1);
    }
  }
  
  return (0);
}

void isFound(const uint16_t Number)
{
  
    if (Number)
      cout<<"Yes, The number has been found :-)"<<endl;
    else
      cout<<"No, The number is not found :-("<<endl;

}

void FreeMemoryAllocation(uint16_t *ptrNum, uint16_t *Arr, uint16_t *NumberToCheck)
{
  delete[](Arr);
  delete(ptrNum);
  delete(NumberToCheck);
}

int main()
{
  srand((unsigned)time(nullptr));

  uint16_t *Length = ReadPositiveNumber("Enter array length: ");
  uint16_t *Arr = nullptr;
  uint16_t *NumberToCheck = nullptr;
  uint16_t Number{0};
  
  GenerateArray(Arr, *Length);
  PrintGeneratedArray(Arr, *Length);
  
  NumberToCheck = ReadPositiveNumber("What's the number you want to search?\n-> ");
  Number = CheckNumberPosition(Arr, *Length, *NumberToCheck);
  isFound(Number);
  
  FreeMemoryAllocation(Length, Arr, NumberToCheck);
  
  return (0);
}
