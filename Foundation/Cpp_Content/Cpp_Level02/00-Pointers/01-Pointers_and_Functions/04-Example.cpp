#include <iostream>

using std::cout;
using std::endl;
using std::string;

int *CalcNumber(int *a, int x)
{
  int Memory{0};
  int *Result = &Memory;
  *Result = (*a) * x;
  return (Result);
}

int main()
{
  int num1 = 3, num2 = 5;
  int *ptr = &num1;
  
  ptr = CalcNumber(&num1, num2);
  cout<<*ptr<<endl;
  return 0;
}
