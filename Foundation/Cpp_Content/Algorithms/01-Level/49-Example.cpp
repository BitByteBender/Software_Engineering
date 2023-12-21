#include <iostream>
#include <cmath>

/**
 * valgrind ./49
 * ==22437== Memcheck, a memory error detector
 * ==22437== Command: ./49
 * ==22437== 
 * Enter a number: 69
 * Using Builtin C++ Sqrt: 8.30662
 * Using My Custom Sqrt Function: 8.30662
 * ==22437== 
 * ==22437== HEAP SUMMARY:
 * ==22437==     in use at exit: 0 bytes in 0 blocks
 * ==22437==   total heap usage: 5 allocs, 5 frees, 74,813 bytes allocated
 * ==22437== 
 * ==22437== All heap blocks were freed -- no leaks are possible
 * ==22437== 
 * ==22437== For lists of detected and suppressed errors, rerun with: -s
 * ==22437== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
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

float _Sqrt(float *ptrNum)
{
  return (pow(*ptrNum, 0.5f));
}

void printSqrtNum(float *ptrNum)
{
  cout<<"Using Builtin C++ Sqrt: "<<sqrt(*ptrNum)<<"\n";
  cout<<"Using My Custom Sqrt Function: "<<_Sqrt((float *)ptrNum)<<"\n";
}

int main(void)
{
  float *Num = ReadNumber("Enter a number: ");
  printSqrtNum((float *)Num);
  
  free(Num);
  return (0);
}
