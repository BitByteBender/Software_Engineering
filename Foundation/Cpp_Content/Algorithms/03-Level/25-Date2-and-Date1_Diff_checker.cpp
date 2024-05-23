#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

struct stDateData
{
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

uint16_t readNum(const char *Msg)
{
  uint16_t Num{0};

  cout<<Msg;
  cin>>Num;

  return (Num);
}

stDateData loadDateRec()
{
  stDateData Dt;

  Dt.Day = readNum("Enter a day: ");
  Dt.Month = readNum("Enter a month: ");
  Dt.Year = readNum("Enter a year: ");
  
  return (Dt);
}

uint16_t isLeapYear(uint16_t Year)
{
  return (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0) ? 366 : 365);
}

uint16_t febCheck(uint16_t Year)
{
  return (isLeapYear(Year) == 366 ? 29 : 28);
}

uint16_t DaysInMonth(uint16_t Year, uint16_t Month)
{
  uint16_t arrMonths[7] = {1, 3, 5, 7, 8, 10, 12};
  return (Month == 2 ? febCheck(Year) : Month == arrMonths[uint16_t(Month / 2)] ? 31 : 30);
}

uint16_t getTotalDays(uint16_t Year, uint16_t Month, uint16_t Day)
{
  uint16_t i = 1, Days = Day;
  
  while (i < Month) {
    Days += DaysInMonth(Year, i);
    i++;
  }
  
  return (Days);
}

uint16_t getDiff(uint16_t arr[2])
{
  return (abs(arr[0] - arr[1]));
}

uint16_t countDiff(uint16_t DiffNum)
{
  return ((DiffNum * 365) + floor(DiffNum / 4));
}

void DisplayDiff(stDateData arrDt[2], uint16_t arr[2])
{
  uint16_t YearDiff = getDiff(arr);
  uint16_t Count = countDiff(YearDiff);
  uint16_t dtTotal1 = getTotalDays(arrDt[0].Year, arrDt[0].Month, arrDt[0].Day);
  uint16_t dtTotal2 = getTotalDays(arrDt[1].Year, arrDt[1].Month, arrDt[1].Day);

  cout<<"Diffrence is: "<<Count + dtTotal1 + dtTotal2 - 1<<'\n';
  cout<<"Difference (Including end day) is: "<<Count + dtTotal1 + dtTotal2<<'\n';
}

int main(void)
{
  stDateData arrDt[2] = {loadDateRec(), loadDateRec()};
  uint16_t arr[2] = {arrDt[0].Year, arrDt[1].Year};
  DisplayDiff(arrDt, arr);

  return (0);
}
