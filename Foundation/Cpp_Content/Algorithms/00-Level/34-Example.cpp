#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadNumber(string Message)
{
  short Num{0};

  cout<<Message;
  cin>>Num;

  return Num;
}

void ReadN(short &N)
{
  N = ReadNumber("Enter N: ");
}

void PrintN(short N)
{
  unsigned short i;
  for (i = N; i >= 1; i--) {
    cout<<i;
    if (i > 1)
    {
      cout<<"\n";
    }
  }
  cout<<endl;
}
int main()
{
  short N{0};

  ReadN(N);
  PrintN(N);
  return 0;
}
