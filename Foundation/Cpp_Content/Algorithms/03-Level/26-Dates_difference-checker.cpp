#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

struct stDate
{
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

uint16_t readData(const char *Msg)
{
  uint16_t Value{0};

  cout<<Msg;
  cin>>Value;

  return (Value);
}

stDate promptDate()
{
  stDate Date;

  Date.Day = readData("Enter a day: ");
  Date.Month = readData("Enter a month: ");
  Date.Year = readData("Enter a year: ");

  return (Date);
}

uint16_t DaysInYear(uint16_t Year)
{
  return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0 ? 366 : 365);
}

uint16_t DaysInFebruary(uint16_t Year)
{
  return (DaysInYear(Year) == 366 ? 29 : 28);
}

uint16_t DaysInMonth(uint16_t Year, uint16_t Month)
{
  uint16_t arrMonths[7] = {1, 3, 5, 7, 8, 10, 12};

  return (Month == 2 ? DaysInFebruary(Year) : Month == arrMonths[Month/2] ? 31 : 30);
}

uint16_t GetRemainingDays(uint16_t Year, uint16_t Month, uint16_t Day)
{
  while (Month > 1) {
    Day += DaysInMonth(Year, --Month);
  }

  return (Month > 1 ? (Day + 31) : Day);
}

uint16_t DiffCheck(uint16_t Year1, uint16_t Year2)
{
  return (abs(Year1 - Year2));
}

uint16_t CountDaysInYearsDiff(stDate Dates[2])
{
  uint16_t Days = 0, i = 0, counter = DiffCheck(Dates[0].Year, Dates[1].Year);

  for (i = 0; i < counter; i++) {
    Days += DaysInYear(Dates[0].Year < Dates[1].Year ? Dates[0].Year++ : --Dates[0].Year);
  }
  
  return (Days - GetRemainingDays(Dates[0].Year, Dates[0].Month, Dates[0].Day) + GetRemainingDays(Dates[1].Year, Dates[1].Month, Dates[1].Day));
}

void DisplayResult(stDate Dates[2])
{
  uint16_t Diff = 0;

  if (Dates[0].Year > Dates[1].Year) {
    Diff = CountDaysInYearsDiff(Dates);
    cout<<"\nDiffrence is: -"
	<<Diff;

    cout<<"\nDiffrence (Including End Day) is: -"
	<<Diff + 1<<endl;
  } else {
    Diff = CountDaysInYearsDiff(Dates);
    cout<<"\nDiffrence is: "
	<<Diff;

    cout<<"\nDiffrence (Including End Day) is: "
	<<Diff + 1<<endl;
  }
}

int main(void)
{
  stDate Date1, Date2;
  
  Date1 = promptDate();
  Date2 = promptDate();
  
  stDate Dates[2] = {Date1, Date2};
  
  cout<<GetRemainingDays(Date1.Year, Date1.Month, Date1.Day)<<endl;
  cout<<DiffCheck(Date1.Year, Date2.Year)<<endl;

  DisplayResult(Dates);
  return (0);
}
