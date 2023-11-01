#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
 * ==30759== HEAP SUMMARY:
 * ==30759== in use at exit: 0 bytes in 0 blocks
 * ==30759== total heap usage: 6 allocs, 6 frees, 74,778 bytes allocated
 * ==30759== 
 * ==30759== All heap blocks were freed -- no leaks are possible
 * ==30759== 
 * ==30759== For lists of detected and suppressed errors, rerun with: -s
 * ==30759== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

uint16_t *ReadNumber(const char *);

uint16_t RandNums(uint16_t [], uint16_t);

void FillArrayWithRandNums(uint16_t [], uint16_t &);

uint16_t *CheckMinNumber(const uint16_t [], uint16_t);

void PrintArrayElements(const uint16_t [], uint16_t, uint16_t);

int main(void)
{
  srand((unsigned)time(NULL));
  
  uint16_t *Length = ReadNumber("Enter number of array elements: ");
  uint16_t *Arr = (uint16_t*)malloc(sizeof(uint16_t) * (*Length + 1));
  
  FillArrayWithRandNums(Arr, *Length);
  uint16_t *MinNumber = CheckMinNumber(Arr, *Length);
  PrintArrayElements(Arr, *Length, *MinNumber);
  
  free(Length);
  free(Arr);
  free(MinNumber);
  return 0;
}


uint16_t *ReadNumber(const char *Message)
{
  uint16_t *ptrNum = (uint16_t*)malloc(sizeof(uint16_t));

  cout<<Message;
  cin>>*ptrNum;

  return (ptrNum);
}

uint16_t RandNums(uint16_t From, uint16_t To)
{
  uint16_t RandNum = (rand() % (To - From + 1) + From);
  return (RandNum);
}

void FillArrayWithRandNums(uint16_t Array[], uint16_t &Length)
{
  uint16_t i = 0;

  for (; i <= (Length - 1); i++) {
    Array[i] = RandNums(1, 100);
  }
}

uint16_t *CheckMinNumber(const uint16_t Array[], uint16_t Length)
{
  uint16_t i = 0, *ptrMinNumber = nullptr;
  
  while ((Length - 1) >= i) {

    if (ptrMinNumber == nullptr) {
      ptrMinNumber = (uint16_t*)malloc(sizeof(uint16_t));
      *ptrMinNumber = Array[i];
    }
    
    if (*ptrMinNumber > Array[i]) {
      *ptrMinNumber = Array[i];
    }
    i++;
  }


  return (ptrMinNumber);
}

void PrintArrayElements(const uint16_t Arr[], uint16_t Length, uint16_t MinNumber)
{
  cout<<"Array Elements: ";
  
  uint16_t i = 0;

  for (; i <= (Length - 1); i++) {
    if (i == (Length - 1)) {
      cout<<Arr[i]<<"\n";
    }
    else
    {
      cout<<Arr[i]<<" ";
    }
  }

  cout<<"Min Number is: "<<MinNumber<<endl;
}
