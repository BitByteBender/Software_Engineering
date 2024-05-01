#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct stData {
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

uint16_t ReadNum(const char *Msg)
{
  uint16_t Num{0};
  
  cout<<Msg;
  cin>>Num;
  
  return (Num);
}

stData promptData()
{
  stData DataTime;

  DataTime.Day = ReadNum("Please enter a day? ");
  DataTime.Month = ReadNum("Please enter a month? ");
  DataTime.Year = ReadNum("Please enter a year? ");
  
  return (DataTime);
}

inline uint16_t isleapYear(uint16_t Year)
{
  return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0) ? 366 : 365);
}

inline uint16_t FebChecker(uint16_t Year)
{
  return (isleapYear(Year) == 366 ? 29 : 28);
}

uint16_t MonthEncoder(uint16_t Month, uint16_t Year)
{
  uint16_t arr[7] = {1, 3, 5, 7, 8, 10, 12};
  return (Month == 2 ? FebChecker(Year) : Month == arr[uint16_t(Month/2)] ? 31 : 30);
}

uint16_t getRemainingDays(uint16_t Day, uint16_t Month, uint16_t Year)
{
  uint16_t i = 0, Days = Day;

  for (i = 1; i <= (Month - 1); i++) {
    Days = Days + MonthEncoder(i, Year);
  }

  return (isleapYear(Year) - Days);
}

void DisplayRemainingDays(stData &dt)
{
  uint16_t Remainder{0};
  
  dt = promptData();
  Remainder = getRemainingDays(dt.Day, dt.Month, dt.Year);

  cout<<"Days left in ["<<dt.Year<<"]: "<<Remainder<<endl;
}

int main(void)
{
  stData dt;
  DisplayRemainingDays(dt);

  return (0);
}

