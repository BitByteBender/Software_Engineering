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

bool DaysChecker(uint16_t Day)
{
  return (Day >= 1 && Day <= 31);
}

bool MonthChecker(uint16_t Day, uint16_t Month)
{
  return ((Month == 2 && Day <= 29) || (Month <= 12 && Month >= 1 && Month != 2 && DaysChecker(Day)));
}

bool YearChecker(uint16_t Year, uint16_t Month, uint16_t Day)
{
  return (Year <= 2024 && MonthChecker(Day, Month));
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

int main(void)
{
  stDate Date = stPrompt();

  cout<<"Day: "<<Date.Day<<"\nMonth: "<<Date.Month<<"\nYear: "<<Date.Year<<endl;
  return (0);
}

