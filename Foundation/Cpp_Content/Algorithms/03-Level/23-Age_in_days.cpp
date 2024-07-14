#pragma warning(disable : 4996)

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct stDate
{
  uint16_t Day = 0, Month = 0, Year = 0;
};
  
uint16_t readNum(string Message)
{
  uint16_t Num{0};

  cout<<Message;
  cin>>Num;

  return (Num);
}

stDate DataReader()
{
  stDate Dt;
  
  Dt.Day = readNum("Enter a day: ");
  Dt.Month = readNum("Enter a Month: ");
  Dt.Year = readNum("Enter a year: ");

  return (Dt);
}

uint16_t isleap(uint16_t Year)
{
  return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0) ? 366 : 365);
}

uint16_t febCheck(uint16_t Year)
{
  return (isleap(Year) != 366 ? 28 : 29);
}

uint16_t DaysInMonth(uint16_t Year, uint16_t Month)
{  
  if (Month == 2)
    return (febCheck(Year));
  else {
    uint16_t arrMonths[7] = {1, 3, 5, 7, 8, 10, 12};
    return (Month != arrMonths[uint16_t(Month/2)] ? 30 : 31);
  }
}

uint16_t YearsDiff(uint16_t BirthYear, uint16_t YearNow)
{
  uint16_t Calc = (365 * (abs(BirthYear - YearNow) - 1) + (abs(BirthYear - YearNow) / 4));
  return (isleap(BirthYear) == 366 ? (Calc-1) : Calc);
}


uint16_t CalcDays(uint16_t Year, uint16_t Month, uint16_t Day)
{
  uint16_t i = 1, Days = Day;
  
  for (; i < Month; i++) {
    Days += DaysInMonth(Year, i);
  }
 
  return (Days);
}

uint16_t RevCalcDays(uint16_t Year, uint16_t Month, uint16_t Day)
{
  uint16_t i = Month, Days = 0;

  for (; i <= 12; i++) {
    Days += DaysInMonth(Year, i);
  }

  return (Days - Day);
}

uint16_t CalcDiff(uint16_t arrDiff[2])
{
  return (abs(arrDiff[0] + arrDiff[1]));
}

void DisplayAgeInDays(string Msg)
{
  time_t t = time(0);
  tm* now = localtime(&t);
  
  stDate dt;
  uint16_t arrDiff[2], Days = 0;
  
  cout<<Msg;

  dt = DataReader();
  arrDiff[0] = RevCalcDays(dt.Year, dt.Month, dt.Day);
  arrDiff[1] = CalcDays(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
  
  Days = CalcDiff(arrDiff) + YearsDiff(dt.Year, now->tm_year + 1900);

  cout<<'\n'<<"Your Age is: "<<Days<<" Day(s)"<<endl;
}

int main(void)
{
  DisplayAgeInDays("Please enter your date of birth:\n");
  return (0);
}
