#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/**
 * ==9355== Memcheck, a memory error detector
 * ==9355== Command: ./40
 * ==9355== 
 * Enter the length array: 3
 * Value-> 10
 * Value-> 20
 * Value-> 10
 * Array elements: 10 20 10
 * Yes, it's a palindrome
 * ==9355== 
 * ==9355== HEAP SUMMARY:
 * ==9355==     in use at exit: 0 bytes in 0 blocks
 * ==9355==   total heap usage: 4 allocs, 4 frees, 74,758 bytes allocated
 * ==9355== 
 * ==9355== All heap blocks were freed -- no leaks are possible
 * ==9355== 
 * ==9355== For lists of detected and suppressed errors, rerun with: -s
 * ==9355== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

uint16_t ReadPositiveNumber(const char *Message)
{
  uint16_t Num = 0;

  do {
    cout<<Message;
    cin>>Num;
  } while (Num <= 0);

  return (Num);
}

void FillArray(uint16_t *&Arr, uint16_t Length)
{
  uint16_t i = 0;
  Arr = (uint16_t *)malloc(sizeof(uint16_t) * (Length));

  for (i = 0; i <= (Length - 1); i++) {
    Arr[i] = ReadPositiveNumber("Value-> ");;
  }
}

void DisplayArray(uint16_t *Arr, uint16_t Length)
{
  uint16_t i = 0;
  cout<<"Array elements: ";

  for (i = 0; i <= (Length - 1); i++) {
    if (i < (Length - 1)) {
      cout<<Arr[i]<<" ";
    }
    else {
      cout<<Arr[i]<<endl;
    }
  }
}

bool isPalindrome(const uint16_t *Arr, const uint16_t Length)
{
  uint16_t startPos = 0, endPos = (Length - 1);

  while (startPos != endPos) {
    if (Arr[startPos] != Arr[endPos]) {
      return (0);
    }
    startPos++;
    endPos--;
  }

  return (1);
}

void DisplayResult(const uint16_t *Arr, const uint16_t Length)
{
  if (isPalindrome(Arr, Length)) {
    cout<<"Yes, it's a palindrome"<<endl;
  }
  else {
    cout<<"No, it's not a palindrome"<<endl;
  }
}

void FreeMemory(uint16_t *Arr)
{
 free(Arr);
}

int main(void)
{
  uint16_t Length = 0;
  uint16_t *Arr = nullptr;

  Length = ReadPositiveNumber("Enter the length array: ");

  FillArray(Arr, Length);
  DisplayArray(Arr, Length);

  isPalindrome(Arr, Length);
  DisplayResult(Arr, Length);

  FreeMemory(Arr);
  return 0;
}
