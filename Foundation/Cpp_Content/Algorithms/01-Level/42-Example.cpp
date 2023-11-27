#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

/**
 * ==13956== 
 * Enter the length: 5
 * Array Elements: 80 27 2 41 45
 * Even Numbers count is: 2
 * ==13956== 
 * ==13956== HEAP SUMMARY:
 * ==13956==     in use at exit: 0 bytes in 0 blocks
 * ==13956==   total heap usage: 5 allocs, 5 frees, 74,766 bytes allocated
 * ==13956== 
 * ==13956== All heap blocks were freed -- no leaks are possible
 * ==13956== 
 * ==13956== For lists of detected and suppressed errors, rerun with: -s
 * ==13956== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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

uint16_t Randomize(uint16_t From, uint16_t To)
{
  uint16_t Rand = rand() % (To - From + 1) + From;
  return (Rand);
}

void FillArray(uint16_t *&Arr, uint16_t *Length)
{
  uint16_t i = 0;
  Arr = (uint16_t *)malloc(sizeof(uint16_t) * (*Length + 1));

  for (i = 0; i <= (*Length - 1); i++) {
    Arr[i] = Randomize(1, 100);
  }
}

void PrintArray(const uint16_t *Arr, const uint16_t *Length, const char *Text)
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

uint16_t CountEvenNums(const uint16_t *Arr, const uint16_t *Length)
{
  uint16_t i = 0, Counter = 0;

  for (i = 0; i <= (*Length - 1); i++) {
    if (Arr[i] % 2 == 0) {
      Counter++;
    }
  }
  return (Counter);
}

void DisplayCountedEvenNums(const uint16_t *Arr, const uint16_t *Length)
{
  cout<<"Even Numbers count is: "<<CountEvenNums(Arr, Length)<<endl;
}

int main(void)
{
  srand(uint16_t(time(nullptr)));
	
  uint16_t *Length = nullptr;
  uint16_t *Arr = nullptr;

  Length = ReadPositiveNumber("Enter the length: ");
  
  FillArray(Arr, Length);
  PrintArray(Arr, Length, "Array Elements: ");

  DisplayCountedEvenNums(Arr, Length);

  free(Length);
  free(Arr);
  
  return (0);
}
