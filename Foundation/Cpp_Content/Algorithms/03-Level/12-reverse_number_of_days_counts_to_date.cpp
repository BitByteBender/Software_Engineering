#include <iostream>

using std::cout;
using std::cin;
using std::endl;


struct stData
{
  uint16_t Day, Month, Year;
};

uint16_t readNum(const char *Msg)
{
  uint16_t Num{0};

  cout<<Msg;
  cin>>Num;

  return (Num);
}

stData readData()
{
  stData dt;

  dt.Day = readNum("Enter a day: ");
  dt.Month = readNum("Enter a month: ");
  dt.Year = readNum("Enter a year: ");

  return (dt);
}

bool isleapYear(uint16_t Year)
{
  return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}

uint16_t secondMonth(uint16_t Year)
{
  return (isleapYear(Year) ? 29 : 28);
}

uint16_t monthSwitcher(uint16_t Month, uint16_t Year)
{
  if (Month < 1 || Month > 12) {
    return (0);
  }
  
  uint16_t arrOfMonths[7] = {1, 3, 5, 7, 8, 10, 12};

  return (arrOfMonths[(Month / 2)] == Month ? 31 : ((Month == 2) ? secondMonth(Year) : 30));
}

uint16_t daysInYear(uint16_t Year)
{
  return (isleapYear(Year) ? 366 : 365);
}

uint16_t daysCount(uint16_t Day, uint16_t Month, uint16_t Year)
{
  uint16_t i = 0, total = 0;

  for (i = 12; i >= Month; i--)
    total += monthSwitcher(i, Year);

  return (daysInYear(Year) - total + Day);
}

void printConsumedDays(stData dt)
{
  cout<<"Number of days from the begining of the year is: "
      <<daysCount(dt.Day, dt.Month, dt.Year)<<endl;
}

uint16_t getMonth(uint16_t Day, uint16_t Month, uint16_t Year)
{
  uint16_t i = 1, total = 0, totalDays = 0;

  totalDays = daysCount(Day, Month, Year);
  
  while (!(total > totalDays)) {
    total += monthSwitcher(i, Year);
    i++;
  }

  if (total > totalDays) {
    i--;
  }
  
  return (i);
}


uint16_t getRemainingDays(uint16_t Day, uint16_t Month, uint16_t Year)
{
  uint16_t total = 0, totalDays = 0, daysByMonth = 0;

  totalDays = daysCount(Day, Month, Year);
  daysByMonth = getMonth(Day, Month, Year);
  
  while (daysByMonth != 0) {
    total += monthSwitcher(daysByMonth, Year);
    daysByMonth--;
  }
  
  daysByMonth = getMonth(Day, Month, Year);
  return (abs(total - (monthSwitcher(daysByMonth, Year) + totalDays)));
}

void printReversed(stData dt)
{

  cout<<"Date for ["<<daysCount(dt.Day, dt.Month, dt.Year)<<"] is: ";
  cout<<getRemainingDays(dt.Day, dt.Month, dt.Year)<<'/'<<getMonth(dt.Day, dt.Month, dt.Year)<<'/'<<dt.Year<<endl;

  
}

int main(void)
{
  stData dt = readData();

  printConsumedDays(dt);
  printReversed(dt);
  return (0);
}
