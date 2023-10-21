#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

short ReadNumber(string Message)
{
  short Num{0};
  short *ptrNum = &Num;

  cout<<Message;
  cin>>*ptrNum;

  return (*ptrNum);
}

bool CheckPerfectOrNot(short *ptrNum)
{
  unsigned short counter, Sum = 0, Max = round(*ptrNum / 2);

  for (counter = 1; counter <= Max; counter++) {
    if (*ptrNum % counter == 0) {
      Sum = Sum + counter;
    }
  }
  
  return (*ptrNum == Sum);
}

void PrintPerfectOrNot(short Num)
{
  if (CheckPerfectOrNot(&Num)) {
    cout<<Num<<" is Perfect"<<endl;
  }
  else
  {
    cout<<Num<<" is not perfect"<<endl;
  }
}

int main()
{
  unsigned short Num = ReadNumber("Enter a number: ");

  PrintPerfectOrNot(Num);
  return 0;
}
