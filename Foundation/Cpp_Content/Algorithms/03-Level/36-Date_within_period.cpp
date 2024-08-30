#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct stDate
{
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

struct stPeriod
{
  stDate StartDate, EndDate;
};

uint16_t *ReadNum(string scrMsg)
{
  uint16_t *ptrNum = new uint16_t;

  cout<<scrMsg;
  cin>>*ptrNum;
  
  return (ptrNum);
}

stDate SaveDates(const char *Msg)
{
  stDate Dt;
  uint16_t * ptrPivot = nullptr;

  cout<<Msg<<'\n';
  
  ptrPivot = ReadNum("Enter a day: ");
  Dt.Day = *ptrPivot;

  ptrPivot = ReadNum("Enter a month: ");
  Dt.Month = *ptrPivot;

  ptrPivot = ReadNum("Enter a year: ");
  Dt.Year = *ptrPivot;
  
  delete ptrPivot;
  
  return (Dt);
}

stPeriod LoadPeriods()
{
  stPeriod Period;

  Period.StartDate = SaveDates("Enter Start Date:\n");
  Period.EndDate = SaveDates("\nEnter End Date:\n");

  return (Period);
}

inline uint16_t isLeapYear(uint16_t Year)
{
  return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0 ? 366 : 365);
}

inline uint16_t FebCheck(uint16_t Year)
{
  return (isLeapYear(Year) == 366 ? 29 : 28);
}

uint16_t getDaysInMonth(uint16_t Month, uint16_t Year)
{
  uint16_t arrMonth[4] = {4, 6, 9, 11};

  return (Month == 2 ? FebCheck(Year) : Month == 1 || Month != arrMonth[uint16_t(round(Month / 3.0f) - 1)] ? 31 : 30);
}

uint16_t TotalDays(stDate Date)
{
  uint16_t TotalDays = Date.Day;

  while (Date.Month > 1)
    TotalDays += getDaysInMonth(--Date.Month, Date.Year);

  return (TotalDays);
}

uint16_t getLength(stPeriod Period)
{
  uint16_t Length = abs(TotalDays(Period.StartDate) - TotalDays(Period.EndDate));

  if (Period.StartDate.Year != Period.EndDate.Year) {
    uint16_t count = abs(Period.EndDate.Year - Period.StartDate.Year);
    while (count != 0)
      Length += isLeapYear(Period.EndDate.Year - (--count));
  }
  
  return (Length);
}

inline bool CheckRange(stPeriod Period)
{
  return (getLength(Period) > 1);
}

bool CheckDate(stPeriod Period, stDate Date)
{
  if (CheckRange(Period)) {
    return ((Period.StartDate.Year <= Date.Year && Date.Year <= Period.EndDate.Year) && (Period.StartDate.Month <= Date.Month && Date.Month <= Period.EndDate.Month) && (Period.StartDate.Day < Date.Day && Date.Day < Period.EndDate.Day) ? true : false);
  } else
    return (false);
}

int main(void)
{
  stPeriod Period = LoadPeriods();
  stDate Dt = SaveDates("\nEnter Date to check:\n\n");
  
  if (CheckDate(Period, Dt))
    cout<<"\nYes, Date is within period"<<endl;
  else
    cout<<"\nNo, Date is not within period"<<endl;
  
  return (0);
}
