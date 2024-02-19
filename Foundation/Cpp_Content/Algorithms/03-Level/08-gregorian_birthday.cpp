#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

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

uint16_t readNum(const char *Msg)
{
  uint16_t Num{0};

  cout<<Msg;
  cin>>Num;

  return (Num);
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

std::string getDay(uint16_t year, uint16_t month, uint16_t day)
{
  uint16_t dayOrder = 0;
  dayOrder = gregorianCalc(year, month, day);
  
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
  }
}

void printBirthday(uint16_t year, uint16_t month, uint16_t day)
{
  uint16_t dayOrder = 0;
  dayOrder = gregorianCalc(year, month, day);
  
  cout<<"Date: "<<month<<'/'<<day<<'/'<<year<<'\n';
  cout<<"Day order: "<<dayOrder<<'\n';
  cout<<"Day name: "<<getDay(year, month, day)<<endl;
}

int main(void)
{
  uint16_t year = readNum("Enter a year: ");
  uint16_t month = readNum("Enter a month: ");
  uint16_t day = readNum("Enter a day: ");

  //cout<<gregorianCalc(year, month, day)<<endl;
  printBirthday(year, month, day);
  return (0);
}
