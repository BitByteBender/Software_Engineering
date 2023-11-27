#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

/**
 * ==14477== Command: ./43
 * ==14477== 
 * Enter the length: 10
 * Array Elements: -24 87 -28 70 -82 -47 75 36 -71 58
 * Positive Numbers count is: 5
 * ==14477== 
 * ==14477== HEAP SUMMARY:
 * ==14477==     in use at exit: 0 bytes in 0 blocks
 * ==14477==   total heap usage: 5 allocs, 5 frees, 74,776 bytes allocated
 * ==14477== 
 * ==14477== All heap blocks were freed -- no leaks are possible
 * ==14477== 
 * ==14477== For lists of detected and suppressed errors, rerun with: -s
 * ==14477== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

uint16_t *ReadPositiveNumber(const char *Msg)
{
  uint16_t *ptrNum = (uint16_t *)malloc(sizeof(uint16_t));

  do {
    cout<<Msg;
    cin>>*ptrNum;
  } while (*ptrNum <= 0);

  return (ptrNum);
}

short Randomize(short From, short To)
{
  short Rand = rand() % (To - From + 1) + From;
  return (Rand);
}

void FillArray(short *&Arr, uint16_t *Length)
{
  uint16_t i = 0;
  Arr = (short *)malloc(sizeof(short) * (*Length + 1));

  for (i = 0; i <= (*Length - 1); i++) {
    Arr[i] = Randomize((-100), 100);
  }
}

void PrintArray(const short *Arr, const uint16_t *Length, const char *Text)
{
  cout<<Text;

  uint16_t i = 0;

  for (i = 0; i <= (*Length - 1); i++) {
    if (i == (*Length - 1)) {
      cout<<Arr[i]<<endl;
    }
    else {
      cout<<Arr[i]<<" ";
    }
  }
}

uint16_t CountPositiveNums(const short *Arr, const uint16_t *Length)
{
  uint16_t i = 0, Counter = 0;

  for (i = 0; i <= (*Length - 1); i++) {
    if (Arr[i] > 0) {
      Counter++;
    }
  }
  return (Counter);
}

void DisplayCountedPositiveNums(const short *Arr, const uint16_t *Length)
{
  cout<<"Positive Numbers count is: "<<CountPositiveNums(Arr, Length)<<endl;
}

int main(void)
{
  srand(uint16_t(time(nullptr)));
	
  uint16_t *Length = nullptr;
  short *Arr = nullptr;

  Length = ReadPositiveNumber("Enter the length: ");
  
  FillArray(Arr, Length);
  PrintArray(Arr, Length, "Array Elements: ");

  DisplayCountedPositiveNums(Arr, Length);

  free(Length);
  free(Arr);
  
  return (0);
}
