#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum enWeekDays
{
  Mo = 0, Tu = 1, We = 2,
  Th = 3, Fr = 4, Sa = 5, Su = 6
};

struct stDateData
{
  uint16_t Day, Month, Year;
};

uint16_t *DataPrompt(const char *Msg)
{
  uint16_t *ptrNum = new uint16_t;

  cout<<Msg;
  cin>>*ptrNum;
  
  return (ptrNum);
}

stDateData DataLoader()
{
  stDateData Date;

  uint16_t *Day = DataPrompt("Enter a Day: ");
  uint16_t *Month = DataPrompt("Enter a Month: ");
  uint16_t *Year = DataPrompt("Enter a Year: ");

  Date.Day = *Day;
  Date.Month = *Month;
  Date.Year = *Year;

  delete Day;
  delete Month;
  delete Year;
  
  return (Date);
}

uint16_t GregorianCalc(stDateData dt)
{
  uint16_t a = 0, m = 0, y = 0;

  a = abs((14 - dt.Month) / 12);
  y = dt.Year - a;
  m = dt.Month + (12 * a) - 2;

  return ((dt.Day + y + abs(y/4) - abs(y/100) + abs(y/400) + abs((31 * m) / 12)) % 7);
}

inline uint16_t DaysConverter(uint16_t Day)
{
  return (Day == 0 ? (Day = 6) : (Day -= 1));
}

std::string DaysMapper(uint16_t Day)
{
  Day = DaysConverter(Day);
  
  switch (Day) {
  case (enWeekDays::Mo):
    return "Monday";
  case (enWeekDays::Tu):
    return "Tuesday";
  case (enWeekDays::We):
    return "Wednesday";
  case (enWeekDays::Th):
    return "Thursday";
  case (enWeekDays::Fr):
    return "Friday";
  case (enWeekDays::Sa):
    return "Saturday";
  case (enWeekDays::Su):
    return "Sunday";
  default:
    return "Not a Weekday!";
  }
}

uint16_t IsLeapYear(uint16_t Year)
{
  return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0) ? 366 : 365);
}

uint16_t FebChecker(uint16_t Year)
{
  return (IsLeapYear(Year) == 365 ? 28 : 29);
}

uint16_t DaysInMonth(uint16_t Month, uint16_t Year)
{
  uint16_t arr[7] = {1, 3, 5, 7, 8, 10, 12};
  return (Month = 2 ? FebChecker(Year) : Month == arr[Month/2] ? 31 : 30);
}

stDateData EndDayChecker(stDateData Dt)
{
  if (Dt.Day == DaysInMonth(Dt.Month, Dt.Year)) {
    if (Dt.Month == 12) {
      Dt.Month = 1;
      Dt.Year++;
    } else {
      Dt.Month++;
    }
    Dt.Day = 1;
  } else {
    Dt.Day++;
  }

  return (Dt);
}

stDateData CalcDifference(stDateData Dt, uint16_t &VacationDays)
{
  uint16_t Day = VacationDays;

  while (Day != 0) {    
    if (DaysConverter(GregorianCalc(Dt)) < 5)
      Day--;

    Dt = EndDayChecker(Dt);   
  }

  return (Dt);
}

void PrintInfo(stDateData Dt)
{
  uint16_t *VacationDays = nullptr;
  
  cout<<"Vacation Starts:\n";
  Dt = DataLoader();
  cout<<'\n';
  
  VacationDays = DataPrompt("Enter vacation days: ");
  
  Dt = CalcDifference(Dt, *VacationDays);
  
  cout<<"Return Date: "
      <<(DaysMapper(GregorianCalc(Dt)))<<", "
      <<Dt.Day<<'/'<<Dt.Month<<'/'<<Dt.Year<<'\n';

  delete VacationDays;
}

int main(void)
{
  stDateData Dt;
  
  PrintInfo(Dt);

  return (0);
}
