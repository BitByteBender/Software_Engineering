#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct stDate
{
  uint16_t Day = 0;
  uint16_t Month = 0;
  uint16_t Year = 0;
};

uint16_t readNum(const char *Msg)
{
  uint16_t Num{0};

  cout<<Msg;
  cin>>Num;

  return (Num);
}

stDate storeDate()
{
  stDate Date;

  Date.Day = readNum("Enter a day: ");
  Date.Month = readNum("Enter a month: ");
  Date.Year = readNum("Enter a year: ");

  return (Date);
}

inline uint16_t isleapYear(uint16_t Year)
{
  return ((Year % 400 != 0 && Year % 100 == 0) || Year % 4 != 0 ? 365 : 366);
}

uint16_t febCheck(uint16_t Year)
{
  return (isleapYear(Year) == 365 ? 28 : 29);
}

uint16_t getDays(uint16_t Year, uint16_t Month)
{
  uint16_t arrMonths[7] = {1, 3, 5, 7, 8, 10, 12};
  return (Month == 2 ? febCheck(Year) : Month != arrMonths[uint16_t(Month / 2)] ? 30 : 31);
}

uint16_t CalcDays(stDate Date)
{
  uint16_t i = 0, Days = Date.Day;

  for (i = 1; i < Date.Month; i++)
    Days += getDays(Date.Year, i);
  
  return (Days);
}

inline uint16_t CalcDiff(uint16_t arrDates[2])
{
  return (arrDates[0] < arrDates[1] ? (arrDates[1] - arrDates[0]) : (arrDates[0] - arrDates[1]));
}

void DisplayResult(uint16_t DiffNum)
{
  cout<<"Difference is: "<<DiffNum<<" Day(s).\n";
  cout<<"Difference (Including End Day) is: "<<DiffNum + 1<<" Day(s)."<<endl;
}

int main(void)
{
  stDate Date0, Date1;
  uint16_t arrDates[2];
  
  Date0 = storeDate(), Date1 = storeDate();
  arrDates[0] = CalcDays(Date0), arrDates[1] = CalcDays(Date1);
  
  DisplayResult(CalcDiff(arrDates));
  return (0);
}
