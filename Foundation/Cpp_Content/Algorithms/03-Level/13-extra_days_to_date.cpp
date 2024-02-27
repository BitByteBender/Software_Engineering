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

uint16_t getDays(uint16_t Day, uint16_t Month, uint16_t Year)
{
  uint16_t i = 0;
  
  for (i = 1; i < Month; i++)
    Day += monthSwitcher(i, Year);
  
  return (Day);
}

uint16_t getYear(uint16_t Day, uint16_t Month, uint16_t Year, uint16_t extraDays)
{
  uint16_t totalDays = 0;

  totalDays = getDays(Day, Month, Year) + extraDays;
  
  while (true) {
    if (totalDays > daysInYear(Year)) {
      totalDays -= daysInYear(Year);
      Year += 1;
      continue;
    } else {
      return (Year);
    }
  }
}

uint16_t getRemainingDays(uint16_t Day, uint16_t Month, uint16_t Year, uint16_t extraDays)
{
  uint16_t totalDays = 0;

  totalDays = getDays(Day, Month, Year) + extraDays;

  if (totalDays < daysInYear(Year)) {
    return (totalDays);
  } else {
    totalDays -= daysInYear(Year);
    return (getRemainingDays(totalDays, 0, Year+1, 0));
  }
}

uint16_t getMonth(uint16_t Day, uint16_t Month,  uint16_t Year, uint16_t extraDays)
{

  Day = getRemainingDays(Day, Month, Year, extraDays);

  Month = 0;
  
  while (Day >= 28) {
    Month++;
    Day -= monthSwitcher(Month, Year);
  }

  return (Month + 1);
}

uint16_t getDays(uint16_t Day, uint16_t Month, uint16_t Year, uint16_t extraDays, uint16_t counter = 1)
{
  uint16_t totalDays = 0, currentYear = 0, currentMonth = 0;

  totalDays = getRemainingDays(Day, Month, Year, extraDays);
  currentYear = getYear(Day, Month, Year, extraDays);
  currentMonth = monthSwitcher(counter, currentYear);
  
  if (totalDays < currentMonth) {
    return (totalDays);
  } else {
    totalDays -= currentMonth;
    return (getDays(totalDays, 0, currentYear, 0, counter + 1));
  }
}

stData storeRec(uint16_t Day,uint16_t Month, uint16_t Year, uint16_t extraDays)
{
  stData dt;

  dt.Day = getDays(Day, Month, Year, extraDays);
  dt.Month = getMonth(Day, Month, Year, extraDays);
  dt.Year = getYear(Day, Month, Year, extraDays);
  
  return (dt);
}
void printReversed(stData dt, uint16_t extraDays)
{
  dt = storeRec(dt.Day, dt.Month, dt.Year, extraDays);
  
  cout<<"Date for ["<<extraDays<<"] is: ";
  cout<<dt.Day<<'/'<<dt.Month<<'/'<<dt.Year<<endl;
}

int main(void)
{
  stData dt = readData();
  uint16_t extraDays = readNum("How many more days? ");
  
  printReversed(dt, extraDays);
  return (0);
}
