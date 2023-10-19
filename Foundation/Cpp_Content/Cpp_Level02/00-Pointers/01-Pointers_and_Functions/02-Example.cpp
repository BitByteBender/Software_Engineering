#include <iostream>

using std::cout;
using std::endl;
using std::cin;

short ReadNumber(std::string Message)
{
  short Num{0};

  cout<<Message;
  cin>>Num;

  return (Num);
}

short CalcInYears(short Age, short* Years)
{
  short NumberOfYears = *Years;
  
  return (Age * (NumberOfYears));
}


int main()
{
  short Age{0};
  short* ptr = &Age;
  short Years{0};
  short* ptrYears = &Years;

  *ptrYears = 3;

  *ptr = ReadNumber("Enter your age: ");
  cout<<CalcInYears(*ptr, ptrYears)<<endl;
  return (0);
}
