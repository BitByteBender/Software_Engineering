#include <iostream>
#include <cmath>

/**
 * valgrind ./47
 * ==19661== Memcheck, a memory error detector
 * ==19661== Command: ./47
 * ==19661== 
 * Enter a number: 568.997
 * Using Builtin C++ Floor: 568
 * Using My Custom Floor Function: 568
 * ==19661== 
 * ==19661== HEAP SUMMARY:
 * ==19661==     in use at exit: 0 bytes in 0 blocks
 * ==19661==   total heap usage: 5 allocs, 5 frees, 74,813 bytes allocated
 * ==19661== 
 * ==19661== All heap blocks were freed -- no leaks are possible
 * ==19661== 
 * ==19661== For lists of detected and suppressed errors, rerun with: -s
 * ==19661== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 *
 * Test (2):
 *
 * valgrind ./47
 * ==20774== Memcheck, a memory error detector
 * ==20774== Command: ./47
 * ==20774== 
 * Enter a number: -98.01
 * Using Builtin C++ Floor: -99
 * Using My Custom Floor Function: -99
 * ==20774== 
 * ==20774== HEAP SUMMARY:
 * ==20774==     in use at exit: 0 bytes in 0 blocks
 * ==20774==   total heap usage: 5 allocs, 5 frees, 74,813 bytes allocated
 * ==20774== 
 * ==20774== All heap blocks were freed -- no leaks are possible
 * ==20774== 
 * ==20774== For lists of detected and suppressed errors, rerun with: -s
 * ==20774== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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

int16_t _Floor(float *ptrNum)
{
  if (*ptrNum == (int16_t) *ptrNum) {
    return (*ptrNum);
  } else {
    return (((int16_t)*ptrNum * -1) == abs((int16_t)*ptrNum) ? (*ptrNum - 1) : (*ptrNum));
  }
}

void printFlooredNum(float *ptrNum)
{
  cout<<"Using Builtin C++ Floor: "<<floor(*ptrNum)<<"\n";
  cout<<"Using My Custom Floor Function: "<<_Floor((float*)ptrNum)<<"\n";
}

int main(void)
{
  float *Num = ReadNumber("Enter a number: ");
  printFlooredNum((float*)Num);

  free(Num);
  return 0;
}
