#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

struct stDate
{
  int16_t Day;
  int16_t Month;
  int16_t Year;
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

int16_t TotalDays(uint16_t Day, uint16_t Month, uint16_t Year)
{
  int16_t TotalDays = Day;

  while (Month != 1) {
    TotalDays += DaysInMonth(--Month, Year);
  }
  
  return (TotalDays);
}

stDate DateChecker(stDate Date)
{
  if (Date.Month == 1) {
      Date.Month = 12;
      Date.Year--;
    } else
      Date.Month--;

  return (Date);
}

stDate DateGenerator(stDate Date)
{
  uint16_t i = 1;

  if (Date.Day < 0) {
    Date.Day *= -1;
    double counter = ceil((double)Date.Day / DaysInYear(Date.Year));
    while (counter != 0) {
      Date.Day = abs(Date.Day - DaysInYear(Date.Year--));
      --counter;
    }
  }
    
  if (Date.Day == 0) {
    Date = DateChecker(Date);
    Date.Day = DaysInMonth(Date.Month, Date.Year);
  }

  while (Date.Day > DaysInMonth(i, Date.Year)) {
    Date.Day -= DaysInMonth(i++, Date.Year);
    Date.Month = i;
  }
  
  Date.Day = ((Date.Month > 2 && DaysInYear(Date.Year) == 366) ? (Date.Day += 1) : Date.Day);

  return (Date);
}

stDate DecreaseOneDay(stDate Date)
{
  Date.Day = TotalDays(Date.Day, Date.Month, Date.Year) - 1;
  Date = DateGenerator(Date);
  
  return (Date);
}

stDate DecreaseDateByXDays(stDate Date, uint16_t Days)
{
  Date.Day = TotalDays(Date.Day, Date.Month, Date.Year) - Days;
  Date = DateGenerator(Date);
  
  return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
  Date.Day = TotalDays(Date.Day, Date.Month, Date.Year) - 7;
  Date = DateGenerator(Date);

  return (Date);
}

stDate DecreaseDateByXWeeks(stDate Date, uint16_t Weeks)
{
  cout<<"Total Days: "<<TotalDays(Date.Day, Date.Month, Date.Year)<<'\n';
  cout<<"Date.Day: "<<Date.Day<<'\n';
  Date.Day = TotalDays(Date.Day, Date.Month, Date.Year) - (Weeks * 7);
  cout<<"Date.Day: "<<Date.Day<<'\n';
  Date = DateGenerator(Date);

  return (Date);
}

stDate DecreaseDateByOneMonth(stDate Date)
{
  uint16_t Days = 0;

  Date.Month -= 1;

  if (Date.Month == 0) {
    Date.Month = 12;
    Date.Year--;
  }
  
  Days = DaysInMonth(Date.Month, Date.Year);
  Date.Day = (Date.Day > Days ? Days : Date.Day);
  
  return (Date);
}

stDate DecreaseDateByXMonths(stDate Date, uint16_t Months)
{
  uint16_t i = 0, Days = DaysInMonth(Date.Month, Date.Year);

  for (; i < Months; ++i)
    Date = DateChecker(Date);

  Date.Day = (Date.Day == Days ? DaysInMonth(Date.Month, Date.Year) : Date.Day);
  
  return (Date);
}

int main(void)
{
  stDate Date;
  uint16_t *Value = nullptr;
  
  Date = InsertDate();
  cout<<"Default Date: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;

  cout<<"Days in month(Default Date): "<<DaysInMonth(Date.Month, Date.Year)<<endl;
  
  Date = DecreaseOneDay(Date);
  cout<<"--> Decrease Date By 1 Day: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
  
  Value = DataPrompt("Enter amount of days to be decreased: ");
  
  Date = DecreaseDateByXDays(Date, *Value);
  cout<<"--> Decrease Date By "<<(*Value)<<" Days: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
  delete Value;
  
  Date = DecreaseDateByOneWeek(Date);
  cout<<"--> Decrease Date By 1 Week: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;

  Value = DataPrompt("Enter total of weeks to be decreased: ");
  Date = DecreaseDateByXWeeks(Date, *Value);
  cout<<"--> Decrease Date By "<<(*Value)<<" Weeks: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
  
  delete Value;

  Date = DecreaseDateByOneMonth(Date);
  cout<<"--> Decrease Date By One Month: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;

  Value = DataPrompt("Enter total of months to be decreased: ");

  Date = DecreaseDateByXMonths(Date, *Value);
  cout<<"--> Decrease Date By "<<(*Value)<<" Months: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
  
  delete Value;
  return (0);
}
