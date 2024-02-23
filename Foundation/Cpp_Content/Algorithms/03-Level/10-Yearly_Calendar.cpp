#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::to_string;

enum enDays
{
  Sun = 0,
  Mon = 1,
  Tue = 2,
  Wed = 3,
  Thu = 4,
  Fri = 5,
  Sat = 6,
};

enum enMonths
{
  Jan = 1,
  Feb = 2,
  Mar = 3,
  Apr = 4,
  May = 5,
  Jun = 6,
  Jul = 7,
  Aug = 8,
  Oct = 9,
  Sep = 10,
  Nov = 11,
  Dec = 12
};

struct stCalendar
{
  enDays Days;
  enMonths Months;
  uint16_t Month, Year, Day;
};

std::string getDay(uint16_t dayOrder);

bool isleapYear(uint16_t Num)
{
  return ((Num % 4 == 0 && Num % 100 != 0) || Num % 400 == 0);
}

uint16_t Month2(uint16_t Year)
{
  return (isleapYear(Year) ? 29 : 28);
}

uint16_t monthSwitcher(uint16_t Month, uint16_t Year)
{
  if (Month < 1 || Month > 12)
    return (0);

  short arrMonths[7] = {1, 3, 5, 7, 8, 10, 12};
  
  return (arrMonths[short(Month / 2)] == Month  ? 31 : ((Month == 2) ? Month2(Year) : 30));
}

string spacer(uint16_t Spacer)
{
  uint16_t i = 0;
  string Spaces;
  
  for (i = 0; i < Spacer; ++i) {
    Spaces += ' ';
  }

  return (Spaces);
}

string displayDays(uint16_t Spacer)
{
  string daysLine;
  uint16_t length = 0;
  
  for (length = 0; length < 7; ++length) {
    daysLine += getDay(length) + spacer(Spacer);
  }

  daysLine = daysLine.substr(0, daysLine.length() - Spacer);

  return (daysLine);
}

void calendarHeader(string Month)
{
  printf("_____________[ %s ]_____________\n\n", Month.c_str());
  cout<<displayDays(2)<<'\n'<<endl;
}

uint16_t readNum(const char *Msg)
{
  uint16_t Num{0};

  cout<<Msg;
  cin>>Num;

  return (Num);
}

stCalendar readRec()
{
  stCalendar Cal;

  Cal.Year = readNum("Enter a year: ");

  return (Cal);
}

uint16_t gregorianCalc(uint16_t year, uint16_t month, uint16_t day)
{
  uint16_t a = 0, y = 0, m = 0, d = 0;
  
  a = floor((14 - month) / 12);
  y = year - a;
  m = month + (12 * a) - 2;

  d = (day + y + floor(y/4) - floor(y/100) + floor(y/400) + floor((31 * m) / 12));
  d = d % 7;

  return (d);
}

std::string getDay(uint16_t dayOrder)
{
  switch ((enDays)dayOrder) {
  case (enDays::Sun):
    return ("Sun");
  case (enDays::Mon):
    return ("Mon");
  case (enDays::Tue):
    return ("Tue");
  case (enDays::Wed):
    return ("Wed");
  case (enDays::Thu):
    return ("Thu");
  case (enDays::Fri):
    return ("Fri");
  case (enDays::Sat):
    return ("Sat");
  default:
    return ("This not a day");
  }
}

std::string getMonth(uint16_t Month)
{
  switch ((enMonths)Month) {
  case (enMonths::Jan):
    return ("Jan");
  case (enMonths::Feb):
    return ("Feb");
  case (enMonths::Mar):
    return ("Mar");
  case (enMonths::Apr):
    return ("Apr");
  case (enMonths::May):
    return ("May");
  case (enMonths::Jun):
    return ("Jun");
  case (enMonths::Jul):
    return ("Jul");
  case (enMonths::Aug):
    return ("Aug");
  case (enMonths::Sep):
    return ("Sep");
  case (enMonths::Oct):
    return ("Oct");
  case (enMonths::Nov):
    return ("Nov");
  case (enMonths::Dec):
    return ("Dec");
  default:
    return ("This not a month");
  }
}

void printMonthlyCalendar(stCalendar Cal, uint16_t Month)
{
  uint16_t i = 0, count = 0;
  
  Cal.Month = Month;
  count =  gregorianCalc(Cal.Year, Cal.Month, Cal.Day + 1);
  calendarHeader(getMonth(Cal.Month));

  while (i != monthSwitcher(Cal.Month, Cal.Year) + count) {
    if ((count > 0 && i < count)) {
      cout<<((i + 1) % 7 == 0 ? "\n" : "     ");
    } else {

      uint16_t Adjust = (count == 0 ? (i + 1) : (i - count + 1));

      cout<<(Adjust / 10 == 0 ? "  " : " ")<<Adjust;
      cout<<((i + 1) % 7 == 0 ? "\n" : "  ");
    }
    i++;
  }
  cout<<"\n_________________________________\n\n"<<endl;
}

void printYearlyCalendar(stCalendar Cal)
{
  uint16_t i = 0;
  
  printf("\n\n___________%s: [%d]__________\n\n\n", "Year", Cal.Year);

  for (i = 1; i <= 12; ++i) {
    printMonthlyCalendar(Cal, i);

  }

  cout<<"\n\n______________(End)______________"<<endl;
}

int main(void)
{
  stCalendar Cal = readRec();

  printYearlyCalendar(Cal);
  return (0);
}
