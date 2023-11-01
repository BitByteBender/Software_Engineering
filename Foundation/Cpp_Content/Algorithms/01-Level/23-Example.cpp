#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
 * ==29064== 
 * ==29064== HEAP SUMMARY:
 * ==29064==     in use at exit: 0 bytes in 0 blocks
 * ==29064==   total heap usage: 6 allocs, 6 frees, 74,778 bytes allocated
 * ==29064== 
 * ==29064== All heap blocks were freed -- no leaks are possible
 * ==29064== 
 * ==29064== For lists of detected and suppressed errors, rerun with: -s
 * ==29064== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

uint16_t *ReadNumber(const char *);

uint16_t RandNums(uint16_t [], uint16_t);

void FillArrayWithRandNums(uint16_t [], uint16_t &);

uint16_t CheckMaxNumber(const uint16_t [], uint16_t);

void PrintArrayElements(const uint16_t [], uint16_t);

int main(void)
{
  srand((unsigned)time(NULL));
  
  uint16_t *Length = ReadNumber("Enter number of array elements: ");
  uint16_t *Arr = (uint16_t*)malloc(sizeof(uint16_t) * (*Length + 1));
  
  FillArrayWithRandNums(Arr, *Length);
  PrintArrayElements(Arr, *Length);
  
  free(Length);
  free(Arr);
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

  Array[Length] = '\0';
}

uint16_t CheckMaxNumber(const uint16_t Array[], uint16_t Length)
{
  uint16_t i = 0, *ptrMaxNumber = nullptr, MaxNumber = 0;
  
  while ((Length - 1) >= i) {

    if (ptrMaxNumber == nullptr) {
      ptrMaxNumber = (uint16_t*)malloc(sizeof(uint16_t));
      *ptrMaxNumber = 0;
    }
    
    if (*ptrMaxNumber < Array[i]) {
      *ptrMaxNumber = Array[i];
    }
    i++;
  }

  MaxNumber = *ptrMaxNumber;
  free(ptrMaxNumber);
  return (MaxNumber);
}

void PrintArrayElements(const uint16_t Arr[], uint16_t Length)
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

  cout<<"Max Number is: "<<CheckMaxNumber(Arr, Length)<<endl;
}
