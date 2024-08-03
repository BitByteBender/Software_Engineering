#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

struct stDate
{
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

uint16_t *DataPrompt(const char *Message)
{
  uint16_t *Number = new uint16_t;

  cout<<Message;
  cin>>*Number;

  return (Number);
}

stDate InsertDate()
{
  stDate Date;
  uint16_t *Day = DataPrompt("Enter a day: ");
  uint16_t *Month = DataPrompt("Enter a month: ");
  uint16_t *Year = DataPrompt("Enter a year: ");
  
  Date.Day = *Day;
  Date.Month = *Month;
  Date.Year = *Year;

  delete(Day);
  delete(Month);
  delete(Year);
  
  return (Date);
}

uint16_t DaysInYear(uint16_t Year)
{
  return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0 ? 366 : 365);
}

uint16_t FebCheck(uint16_t Year)
{
  return (DaysInYear(Year) == 366 ? 29 : 28);
}

uint16_t DaysInMonth(uint16_t Month, uint16_t Year)
{
  uint16_t arr[4] = {4, 6, 9, 11};
  
  if (Month == 1)
    return (31);

  return (Month == 2 ? FebCheck(Year) : Month == arr[uint16_t(round(Month / 3.0f) - 1)] ? 30 : 31);
}

uint16_t TotalDays(uint16_t Day, uint16_t Month, uint16_t Year)
{
  uint16_t TotalDays = Day;

  while (Month != 1) {
    TotalDays += DaysInMonth(--Month, Year);
  }
  
  return (TotalDays);
}

stDate DateGenerator(stDate Date)
{
  uint16_t i = 0, Remainder = abs(DaysInYear(Date.Year) - Date.Day);

  cout<<"<func>Days: "<<Date.Day<<endl;
  cout<<"<func>Remainder: "<<Remainder<<endl;
  cout<<"<func>Month Calc: "<<DaysInMonth(Date.Month, Date.Year)<<endl;
  
  if (Remainder >= DaysInMonth(Date.Month, Date.Year)) {
    uint16_t counter = Remainder / DaysInMonth(Date.Month, Date.Year);
    Date.Month -= counter;
    cout<<"<func 1> Date Month: "<<Date.Month<<endl;
  }

  i = Date.Month;
  
  while (Date.Day > DaysInMonth(i, Date.Year)) {
    cout<<"<func 2>Date Month: "<<i<<endl;
    Date.Day -= DaysInMonth(--i, Date.Year);
  }
  
  return (Date);
}


stDate DecreaseOneDay(stDate Date)
{
  Date.Day = TotalDays(Date.Day, Date.Month, Date.Year) - 1;
  Date = DateGenerator(Date);
  
  return (Date);
}

stDate DecreaseDays(stDate Date, uint16_t Days)
{
  cout<<"<func> check Day: "<<Date.Day<<endl;
  Date.Day = abs(TotalDays(Date.Day, Date.Month, Date.Year) - Days);
  
  cout<<"<func>Day: "<<Date.Day<<'/'<<" Month: "<<Date.Month<<endl;
  Date = DateGenerator(Date);
  
  return (Date);
}

int main(void)
{
  stDate Date;
  uint16_t *Value = new uint16_t;
  
  Date = InsertDate();
  cout<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;

  cout<<DaysInMonth(Date.Month, Date.Year)<<endl;

  //cout<<TotalDays(Date.Day, Date.Month, Date.Year)<<endl;

  //Date = DateGenerator(Date);
  //cout<<"Date Generator: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;

  Date = DecreaseOneDay(Date);
  cout<<"Decrease Date By 1 Day: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
  
  Value = DataPrompt("Enter amount of days to be decreased: ");
  
  Date = DecreaseDays(Date, *Value);
  cout<<"Decrease Date By "<<(*Value)<<" Days: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
  
  return (0);
}
