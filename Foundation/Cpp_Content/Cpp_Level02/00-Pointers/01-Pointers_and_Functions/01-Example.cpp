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

void ReadAge(short* Age)
{
  *Age = ReadNumber("Enter your age: ");
}

short CalcInYears(short Age, short* Years)
{
  return (*(Years) + Age);
}


int main()
{
  short Age{0};
  short* ptr = &Age;
  short Years{0};
  short* ptrYears = &Years;

  *ptrYears = 3;

  ReadAge(ptr);
  cout<<CalcInYears(*ptr, ptrYears)<<"\n";
  return (0);
}
