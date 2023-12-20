#include <iostream>
#include <cmath>

/**
 * valgrind ./48
 * ==19605== Memcheck, a memory error detector
 * ==19605== Command: ./48
 * ==19605== 
 * Enter a number: 54.001
 * Using Builtin C++ Ceil: 55
 * Using My Custom Ceil Function: 55
 * ==19605== 
 * ==19605== HEAP SUMMARY:
 * ==19605==     in use at exit: 0 bytes in 0 blocks
 * ==19605==   total heap usage: 5 allocs, 5 frees, 74,813 bytes allocated
 * ==19605== 
 * ==19605== All heap blocks were freed -- no leaks are possible
 * ==19605== 
 * ==19605== For lists of detected and suppressed errors, rerun with: -s
 * ==19605== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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

int16_t _Ceil(float *ptrNum)
{
  if (*ptrNum == (int16_t) *ptrNum) {
    return (*ptrNum);
  } else {
    return ((int16_t)*ptrNum + 1);
  }
}

void printCeiledNum(float *ptrNum)
{
  cout<<"Using Builtin C++ Ceil: "<<ceil(*ptrNum)<<"\n";
  cout<<"Using My Custom Ceil Function: "<<_Ceil((float*)ptrNum)<<"\n";
}

int main(void)
{
  float *Num = ReadNumber("Enter a number: ");
  printCeiledNum((float*)Num);

  free(Num);
  return 0;
}
