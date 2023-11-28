#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int16_t *ReadNumber(const char *Msg)
{
  int16_t *ptrNum{(int16_t *)malloc(sizeof(int16_t))};

  cout<<Msg;
  cin>>*ptrNum;

  return (ptrNum);
}

uint16_t _abs(int16_t *ptrNum)
{
  return (*ptrNum <= 0 ? ((*ptrNum) * -1) : (*ptrNum)); 
}

void PrintABS(int16_t Number1, int16_t Number2)
{
  cout<<"My abs Result: "<<Number1<<endl;
  cout<<"C++ abs Result: "<<abs(Number2)<<endl;
}

int main(void)
{
  int16_t *Number = nullptr;

  Number = ReadNumber("Enter a Number: ");

  PrintABS(_abs(Number), *Number);

  free(Number);
  return (0);
}
