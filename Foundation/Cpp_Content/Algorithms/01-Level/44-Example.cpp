#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

/**
 * ==14724== Command: ./44
 * ==14724== 
 * Enter the length: 10
 * Array Elements: -90 36 -56 79 -86 -46 -59 -16 -100 12
 * Negative Numbers count is: 7
 * ==14724== 
 * ==14724== HEAP SUMMARY:
 * ==14724==     in use at exit: 0 bytes in 0 blocks
 * ==14724==   total heap usage: 5 allocs, 5 frees, 74,776 bytes allocated
 * ==14724== 
 * ==14724== All heap blocks were freed -- no leaks are possible
 * ==14724== 
 * ==14724== For lists of detected and suppressed errors, rerun with: -s
 * ==14724== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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

uint16_t CountNegativeNums(const short *Arr, const uint16_t *Length)
{
  uint16_t i = 0, Counter = 0;

  for (i = 0; i <= (*Length - 1); i++) {
    if (Arr[i] < 0) {
      Counter++;
    }
  }
  return (Counter);
}

void DisplayCountedNegativeNums(const short *Arr, const uint16_t *Length)
{
  cout<<"Negative Numbers count is: "<<CountNegativeNums(Arr, Length)<<endl;
}

int main(void)
{
  srand(uint16_t(time(nullptr)));
	
  uint16_t *Length = nullptr;
  short *Arr = nullptr;

  Length = ReadPositiveNumber("Enter the length: ");
  
  FillArray(Arr, Length);
  PrintArray(Arr, Length, "Array Elements: ");

  DisplayCountedNegativeNums(Arr, Length);

  free(Length);
  free(Arr);
  
  return (0);
}
