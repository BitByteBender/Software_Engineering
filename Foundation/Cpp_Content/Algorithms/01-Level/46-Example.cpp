#include <iostream>
#include <cmath>
#include <stdlib.h>

/**
 * Test (1):
 *
 * valgrind ./46
 * ==17963== Memcheck, a memory error detector
 * ==17963== Command: ./46
 * ==17963== 
 * Enter a number: 78.5
 * Using Builtin C++ Round: 79
 * Using My Custom Round Function: 79
 * ==17963== 
 * ==17963== HEAP SUMMARY:
 * ==17963==     in use at exit: 0 bytes in 0 blocks
 *==17963==   total heap usage: 5 allocs, 5 frees, 74,813 bytes allocated
 * ==17963== 
 * ==17963== All heap blocks were freed -- no leaks are possible
 * ==17963== 
 * ==17963== For lists of detected and suppressed errors, rerun with: -s
 * ==17963== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 *
 * Test (2):
 *
 * valgrind ./46
 * ==18003== Memcheck, a memory error detector
 * ==18003== Command: ./46
 * ==18003== 
 * Enter a number: 53.2
 * Using Builtin C++ Round: 53
 * Using My Custom Round Function: 53
 * ==18003== 
 * ==18003== HEAP SUMMARY:
 * ==18003==     in use at exit: 0 bytes in 0 blocks
 * ==18003==   total heap usage: 5 allocs, 5 frees, 74,813 bytes allocated
 * ==18003== 
 * ==18003== All heap blocks were freed -- no leaks are possible
 * ==18003== 
 * ==18003== For lists of detected and suppressed errors, rerun with: -s
 * ==18003== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 *
 * Test (3):
 *
 * valgrind ./46
 * ==18006== Memcheck, a memory error detector
 * ==18006== Command: ./46
 * ==18006== 
 * Enter a number: 53
 * Using Builtin C++ Round: 53
 * Using My Custom Round Function: 53
 * ==18006== 
 * ==18006== HEAP SUMMARY:
 * ==18006==     in use at exit: 0 bytes in 0 blocks
 * ==18006==   total heap usage: 5 allocs, 5 frees, 74,813 bytes allocated
 * ==18006== 
 * ==18006== All heap blocks were freed -- no leaks are possible
 * ==18006== 
 * ==18006== For lists of detected and suppressed errors, rerun with: -s
 * ==18006== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 *
 * Test (4):
 *
 * valgrind ./46
 * ==18008== Memcheck, a memory error detector
 * ==18008== Command: ./46
 * ==18008== 
 * Enter a number: 756.6
 * Using Builtin C++ Round: 757
 * Using My Custom Round Function: 757
 * ==18008== 
 * ==18008== HEAP SUMMARY:
 * ==18008==     in use at exit: 0 bytes in 0 blocks
 * ==18008==   total heap usage: 5 allocs, 5 frees, 74,813 bytes allocated
 * ==18008== 
 * ==18008== All heap blocks were freed -- no leaks are possible
 * ==18008== 
 * ==18008== For lists of detected and suppressed errors, rerun with: -s
 * ==18008== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 * 
 * Test (5):
 *
 * valgrind ./46
 * ==20341== Memcheck, a memory error detector
 * ==20341== Command: ./46
 * ==20341== 
 * Enter a number: -78.5
 * Using Builtin C++ Round: -79
 * Using My Custom Round Function: -79
 * ==20341== 
 * ==20341== HEAP SUMMARY:
 * ==20341==     in use at exit: 0 bytes in 0 blocks
 * ==20341==   total heap usage: 5 allocs, 5 frees, 74,813 bytes allocated
 *==20341== 
 * ==20341== All heap blocks were freed -- no leaks are possible
 * ==20341== 
 * ==20341== For lists of detected and suppressed errors, rerun with: -s
 * ==20341== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

using std::cout,
      std::cin,
      std::endl;

float *ReadNumber(const char *Msg)
{
  float *ptrNum{(float *) malloc(sizeof(float))};

  cout<<Msg;
  cin>>*ptrNum;
  
  return (ptrNum);
}

int16_t _Round(float *ptrNum)
{
  if (*ptrNum == (int16_t) *ptrNum) {
    return (*ptrNum);
  } else {
    if (*ptrNum != abs(*ptrNum)) {
      return (abs(*ptrNum - (int16_t) *ptrNum) < 0.5f ? ((int16_t)*ptrNum) : (*ptrNum - 1));
    } else {
      return (abs(*ptrNum - (int16_t) *ptrNum) >= 0.5f ? (*ptrNum + 1) : ((int16_t)*ptrNum));
    }
  }
}

void printRoundedNum(float *ptrNum)
{
  cout<<"Using Builtin C++ Round: "<<round(*ptrNum)<<"\n";
  cout<<"Using My Custom Round Function: "<<_Round((float*)ptrNum)<<"\n";
}

int main(void)
{
  float *Num = ReadNumber("Enter a number: ");
  printRoundedNum((float*)Num);

  free(Num);
  return (0);
}

