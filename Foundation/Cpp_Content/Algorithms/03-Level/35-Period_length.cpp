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

stDate SaveRecord()
{
  stDate Dt;
  uint16_t * ptrPivot = nullptr;
  
  ptrPivot = ReadNum("Enter a day: ");
  Dt.Day = *ptrPivot;

  ptrPivot = ReadNum("Enter a month: ");
  Dt.Month = *ptrPivot;

  ptrPivot = ReadNum("Enter a year: ");
  Dt.Year = *ptrPivot;
  
  delete ptrPivot;
  
  return (Dt);
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

uint16_t TotalDaysInDate(stDate Dt)
{
  uint16_t TotalDays = Dt.Day;

  while (Dt.Month > 1)
    TotalDays += getDaysInMonth(--Dt.Month, Dt.Year);
  
  return (TotalDays);
}

uint16_t getLength(stPeriod Period)
{
  uint16_t Length = abs(TotalDaysInDate(Period.StartDate) - TotalDaysInDate(Period.EndDate));
  
  if (Period.StartDate.Year != Period.EndDate.Year) {
    uint16_t Count = abs(Period.EndDate.Year - Period.StartDate.Year);
    while (Count != 0) 
      Length += isLeapYear(Period.EndDate.Year - (--Count));
  }
  
  return (Length);
}

int main(void)
{
  stPeriod Period;
  uint16_t Length{0};
  
  cout<<"Enter Start Date:\n\n";
  Period.StartDate = SaveRecord();
  
  cout<<"\nEnter End Date:\n\n";
  Period.EndDate = SaveRecord();

  Length = getLength(Period);

  cout<<"\nPeriod Length is: "<<Length<<'\n';
  cout<<"Period Length is (Including End Date): "<<(Length + 1)<<endl;

  return (0);
}
