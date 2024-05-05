#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct stDate
{
  uint16_t Day = 0;
  uint16_t Month = 0;
  uint16_t Year = 0;
};

uint16_t PromptNum(string Msg)
{
  uint16_t Num{0};
  
  cout<<Msg;
  cin>>Num;

  return (Num);
}

uint16_t isleapYear(uint16_t Year)
{
  return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0) ? 366 : 365);
}

uint16_t febChecker(uint16_t Year)
{
  return (isleapYear(Year) == 366 ? 29 : 28);
}

uint16_t getDays(uint16_t Year, uint16_t Month)
{
  uint16_t arr[7] = {1, 3, 5, 7, 8, 10, 12};
  return (Month == 2 ? febChecker(Year) : Month == arr[uint16_t(Month/2)] ? 31 : 30);
}

bool MonthChecker(uint16_t Year, uint16_t Day, uint16_t Month)
{
  return (getDays(Year, Month) >= Day);
}

bool YearChecker(uint16_t Year, uint16_t Month, uint16_t Day)
{
  return (Year <= 2024 && MonthChecker(Year, Day, Month));
}

stDate stPrompt()
{
  stDate Date;
  uint16_t Day = 0, Month = 0, Year = 0;
  bool Checker = YearChecker(Year, Month, Day);
  
  do {
    Day = PromptNum("Enter a day: ");
    Month = PromptNum("Enter a month: ");
    Year = PromptNum("Enter a year: ");
    Checker = YearChecker(Year, Month, Day);
    
    if (!Checker) {
      cout<<"Wrong! entries.\nPlease, verify your data!\nRe-enter:"<<endl;
    }
  } while (!Checker);

  Date.Day = Day;
  Date.Month = Month;
  Date.Year = Year;

  return (Date);
}

uint16_t getInitialYearDays(uint16_t Day, uint16_t Month, uint16_t Year)
{
  uint16_t i = 0, DaysCounter = Day;

  for (i = 1; i < Month; i++) {
    DaysCounter += getDays(Year, i);
  }

  return (DaysCounter);
}

void DisplayInitialDaysOfYear(stDate &Date)
{
  cout<<"Number of Days from the beginning of the year is "<<getInitialYearDays(Date.Day, Date.Month, Date.Year)<<endl;
}

int main(void)
{
  stDate Date = stPrompt();
  DisplayInitialDaysOfYear(Date);
  return (0);
}
