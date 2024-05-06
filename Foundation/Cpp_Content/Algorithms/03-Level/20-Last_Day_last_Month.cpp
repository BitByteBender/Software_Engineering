#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct stDate
{
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

uint16_t *PromptNum(const char *Message)
{
  uint16_t *Num = (uint16_t *)malloc(sizeof(uint16_t));

  cout<<Message;
  cin>>*Num;

  return (Num);
}

stDate promptData()
{
  stDate dt;
  uint16_t *ptrNum;
  
  ptrNum = PromptNum("Enter a Day: ");
  dt.Day = *ptrNum;
  free(ptrNum);
  
  ptrNum = PromptNum("Enter a Month: ");
  dt.Month = *ptrNum;
  free(ptrNum);
  
  ptrNum = PromptNum("Enter a year: ");
  dt.Year = *ptrNum;
  free(ptrNum);
  cout<<'\n';
  
  return (dt);
}

uint16_t isleapYear(uint16_t Year)
{
  return (Year % 400 || (Year % 4 == 0 && Year % 100 != 0) ? 366 : 365);
}

uint16_t febCheck(uint16_t Year)
{
  return (isleapYear(Year) ? 29 : 28);
}

uint16_t getDays(uint16_t Year, uint16_t Month)
{
  uint16_t arrMonths[7] = {1, 3, 5, 7, 8, 10, 12};
  return (Month == 2 ? febCheck(Year) : Month == arrMonths[uint16_t(Month/2)] ? 31 : 30);
}

bool isLastMonth(uint16_t Month)
{
  return (Month == 12);
}

bool isLastDay(uint16_t Day, uint16_t Month, uint16_t Year)
{
  return (Day == getDays(Year, Month));
}

void DisplayResult(stDate &Dt)
{
  if (isLastDay(Dt.Day, Dt.Month, Dt.Year)) {
    cout<<"Yes, Day is Last Day in Month\n";
    if (isLastMonth(Dt.Month))
      cout<<"Yes, Month is Last Month in Year"<<endl;
    else
      cout<<"No, Month is not the Last Month in Year"<<endl;
  } else {
    cout<<"No, Day is not the Last Day in Month\n";
    if (isLastMonth(Dt.Month))
      cout<<"Yes, Month is Last Month in Year"<<endl;
    else
      cout<<"No, Month is not the Last Month in Year"<<endl;
  }
}

int main(void)
{
  stDate Dt = promptData();

  DisplayResult(Dt);
  return (0);
}
