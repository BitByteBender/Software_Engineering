#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

/**
 * Enter array length: 5
 * Array 1 elements: 93 56 58 49 91
 * What's the number you want to search?
 * -> 58
 * Number your are looking for is: 58
 * The number found at position: 2
 * The number found its order: 3
 * ==120488== 
 * ==120488== HEAP SUMMARY:
 * ==120488==     in use at exit: 0 bytes in 0 blocks
 * ==120488==   total heap usage: 15 allocs, 15 frees, 74,776 bytes allocated
 * ==120488== 
 * ==120488== All heap blocks were freed -- no leaks are possible
 * ==120488== 
 * ==120488== For lists of detected and suppressed errors, rerun with: -s
 * ==120488== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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

void GenerateArray(uint16_t *Arr[], uint16_t Length)
{
  uint16_t i = 0, *RandNum = nullptr;

  for (i = 0; i <= (Length - 1); i++) {
    Arr[i] = new uint16_t;
    
    RandNum = GetRandomNumber(1, 100);
    *Arr[i] = *RandNum;
    
    delete (RandNum);
  }

  Arr[Length] = nullptr;
}

void PrintGeneratedArray(uint16_t *Arr[], const uint16_t Length)
{
  cout<<"Array 1 elements: ";

  uint16_t i = 0;

  for (i = 0; i <= (Length - 1); i++) {
    if (i < (Length - 1)) {
      cout<<*Arr[i]<<" ";
    }
    else {
      cout<<*Arr[i]<<endl;
    }
  }
}

void CheckNumber(uint16_t *Arr[], const uint16_t Length, const uint16_t Number)
{
  cout<<"Number your are looking for is: "<<Number<<"\n";

  uint16_t i = 0;

  for (i = 0; i <= (Length - 1); i++) {
    if (*Arr[i] == Number ) {
      cout<<"The number found at position: "<<i<<'\n';
      cout<<"The number found its order: "<<(i + 1)<<'\n';
      break;
    }
    else {
      if (i == (Length - 1)) {
	cout<<"The number is not found :-("<<endl;
	break;
      }
    }
  }
}

void FreeMemoryAllocation(uint16_t *ptrNum, uint16_t *Arr[], uint16_t *NumberToCheck)
{
  uint16_t i = 0;

  for (i = 0; i <= (*ptrNum - 1); i++) {
    delete(Arr[i]);
  }

  delete(ptrNum);
  delete(NumberToCheck);
}

int main()
{
  srand((unsigned)time(nullptr));

  uint16_t *Length = ReadPositiveNumber("Enter array length: ");
  uint16_t *Arr[*Length + 1];
  uint16_t *NumberToCheck = nullptr;
  
  GenerateArray(Arr, *Length);
  PrintGeneratedArray(Arr, *Length);
  
  NumberToCheck = ReadPositiveNumber("What's the number you want to search?\n-> ");
  CheckNumber(Arr, *Length, *NumberToCheck);
  
  FreeMemoryAllocation(Length, Arr, NumberToCheck);
  return 0;
}
