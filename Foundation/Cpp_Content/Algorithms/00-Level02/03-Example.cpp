#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::string;

short *ReadNumber(string Message)
{
  short Num{0}, *ptrNum = &Num;

  cout<<Message;
  cin>>*ptrNum;

  return (ptrNum);
}

bool isPerfect(short *ptrNum)
{
  unsigned short counter, Sum{0};
  short HalfNumber = round(*ptrNum / 2);

  for (counter = 1; counter <= HalfNumber; counter++) {
    if (*ptrNum % counter == 0) {
      Sum += counter;
    }
  }
  
  return (*ptrNum == Sum);
}

void PrintPerfectOrNot(short Num)
{
  short i;

  for (i = 1; i <= Num; i++) {
    if (isPerfect(&i)) {
      cout<<i<<"\n";
    }

  }

  cout<<endl;
}

int main()
{

  PrintPerfectOrNot(*ReadNumber("Enter a number to check: "));
  return 0;
}
