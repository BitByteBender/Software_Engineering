#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct stDate
{
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

uint16_t prompt(const char *Msg)
{
  uint16_t Value{0};

  cout<<Msg;
  cin>>Value;

  return (Value);
}

stDate promptCall()
{
  stDate Date;

  Date.Day = prompt("Enter a day: ");
  Date.Month = prompt("Enter a month: ");
  Date.Year = prompt("Enter a year: ");
  
  return (Date);
}

uint16_t isLeapYear(uint16_t Year)
{
  return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0 ? 366 : 365);
}

uint16_t FebCheck(uint16_t Year)
{
  return (isLeapYear(Year) == 366 ? 29 : 28);
}

uint16_t DaysInMonth(uint16_t Month, uint16_t Year)
{
  uint16_t arrMonths[7] = {1, 3, 5, 7, 8, 10, 12};
  return (Month == 2 ? FebCheck(Year) : Month == arrMonths[Month/2] ? 31 : 30);
}

stDate IncreaseDateByOneDay(stDate &Date)
{
  uint16_t Day = Date.Day, Month = Date.Month, Year = Date.Year;

  if (Day >= DaysInMonth(Month, Year)) {
    Day = 1;
    if (Month == 12) {
      Month = 1;
      Year++;
    } else {
      Month++;
    }
  } else {
    Day += 1;
    if (Month == 12) {
      Month = 1;
      Year++;
    }
  }

  Date.Day = Day;
  Date.Month = Month;
  Date.Year = Year;
  
  return (Date);
}

stDate IncreaseDateByXDays(stDate &Date, uint16_t ExtraDays)
{
  uint16_t Day = Date.Day + ExtraDays;

  while (Day > DaysInMonth(Date.Month, Date.Year)) {
    Day -= DaysInMonth(Date.Month, Date.Year);
    Date.Month++;
  }

  Date.Day = Day;
  return (Date);
}

stDate IncreaseByOneWeek(stDate Date)
{
  Date = IncreaseDateByXDays(Date, 7);

  return (Date);
}

stDate IncreaseDateByXWeeks(stDate Date, uint16_t ExtraWeeks)
{
  uint16_t i = 0;

  for (i = 0; i < ExtraWeeks; ++i) {
    Date = IncreaseByOneWeek(Date);
  }

  return (Date);
}

/*
--- Another Method ---
stDate IncreaseDateByXWeeks(stDate Date, uint16_t ExtraWeeks)
{
  while (ExtraWeeks != 0) {
    if (Date.Day <= (DaysInMonth(Date.Month, Date.Year) - 7)) {
      Date.Day += 7;
    } else {
      Date.Day = abs(DaysInMonth(Date.Month, Date.Year) - (Date.Day + 7));
      Date.Month++;

      if (Date.Month > 12) {
	Date.Month = 1;
	Date.Year++;
      }
    }
    ExtraWeeks--;
  }

  return (Date);
}
*/

stDate IncreaseDateByOneMonth(stDate Date)
{
  uint16_t Day = Date.Day;
  
  Date = IncreaseDateByXWeeks(Date, 4);

  Date.Day = (Day > DaysInMonth(Date.Month, Date.Year) ? DaysInMonth(Date.Month, Date.Year) : Day);

  return (Date);
}

stDate IncreaseDateByXMonths(stDate Date, uint16_t ExtraMonths)
{
  uint16_t i = 0;

  for (i = 0; i < ExtraMonths; ++i) {
    Date = IncreaseDateByOneMonth(Date);
  }

  return (Date);
}

int main(void)
{
  stDate Date = promptCall();
  uint16_t ExtraDays{0}, ExtraWeeks{0}, ExtraMonths{0};
  
  Date = IncreaseDateByOneDay(Date);
  cout<<"Increasing Date By One Day: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
  
  ExtraDays = prompt("Enter the ExtraDays: ");
  Date = IncreaseDateByXDays(Date, ExtraDays);
  cout<<"Increasing Date By "<<ExtraDays<<" Days: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
  
  Date = IncreaseByOneWeek(Date);
  cout<<"Increasing Date By One Week: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;

  ExtraWeeks = prompt("Enter the ExtraWeeks: ");
  Date = IncreaseDateByXWeeks(Date, ExtraWeeks);
  cout<<"Increasing Date By "<<ExtraWeeks<<" Weeks: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;

  Date = IncreaseDateByOneMonth(Date);
  cout<<"Increasing Date By One Month: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;

  ExtraMonths = prompt("Enter the ExtraMonths: ");
  Date = IncreaseDateByXMonths(Date, ExtraMonths);
  cout<<"Increasing Date By "<<ExtraMonths<<" Months: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
  return (0);
}
