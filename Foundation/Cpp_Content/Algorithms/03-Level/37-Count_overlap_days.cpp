#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

enum enDateOrder{Before = -1, Equal = 0, After = 1};

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


uint16_t *ReadNum(const char *Msg)
{
  uint16_t *ptrNum = new uint16_t;

  cout<<Msg;
  cin>>*ptrNum;

  return (ptrNum);
}

stDate SaveDateRec(const char *Msg)
{
  stDate Date;
  uint16_t *ptrNum = nullptr;

  cout<<Msg<<'\n';
  ptrNum = ReadNum("Enter a day: ");
  Date.Day = *ptrNum;

  ptrNum = ReadNum("Enter a month: ");
  Date.Month = *ptrNum;

  ptrNum = ReadNum("Enter a year: ");
  Date.Year = *ptrNum;

  delete ptrNum;
  
  return (Date);
}

stPeriod SavePeriodRec(const char *Msg)
{
  stPeriod P;

  cout<<Msg;
  
  P.StartDate = SaveDateRec("Enter start date:\n");
  P.EndDate = SaveDateRec("Enter end date:\n");

  return (P);
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

uint16_t getLength(stDate start, stDate end)
{
  uint16_t Length = abs(TotalDays(start) - TotalDays(end));

  if (start.Year != end.Year) {
    uint16_t count = abs(end.Year - start.Year);
    while (count != 0)
      Length += isLeapYear(end.Year - (--count));
  }

  return (Length);
}

inline bool CheckRange(stDate DateA, stDate DateB)
{
  return (getLength(DateA, DateB) > enDateOrder::After);
}

bool isDate1Before2(stDate DateA, stDate DateB)
{
  return (DateA.Year < DateB.Year || (DateA.Year == DateB.Year && DateA.Month < DateB.Month) || (DateA.Year == DateB.Year && DateA.Month == DateB.Month && DateA.Day < DateB.Day));
}

bool isDate1After2(stDate DateA, stDate DateB)
{
  return (!isDate1Before2(DateA, DateB));
}

bool isDate1Equal2(stDate DateA, stDate DateB)
{
  return (DateA.Year == DateB.Year && DateA.Month == DateB.Month && DateA.Day == DateB.Day);
}

bool CompareDates(stDate DateA, stDate DateB, stDate DateC)
{
  return ((isDate1Before2(DateA, DateC) || isDate1Equal2(DateA, DateC)) && (isDate1After2(DateB, DateC) || isDate1Equal2(DateB, DateC)));
}

bool CheckDate(stDate DateA, stDate DateB, stDate DateC)
{
  if (CheckRange(DateA, DateB)) return (CompareDates(DateA, DateB, DateC));
  else return false;
}

inline bool OverlapCount(stDate DA, stDate DB, stDate DC)
{
  return (CheckDate(DA, DB, DC));
}

int main(void)
{
  stPeriod P[2];

  P[0] = SavePeriodRec("Enter Period 1:\n");
  P[1] = SavePeriodRec("\nEnter Period 2:\n");

  
  if (OverlapCount(P[0].StartDate, P[0].EndDate, P[1].StartDate)) {
    cout<<"\nOverlap Days Count Is: "<<(getLength(P[0].StartDate, P[1].StartDate) + 1)<<endl;
  } else
    cout<<"\nNo Overlaping days!"<<endl;
  
  return (0);
}
