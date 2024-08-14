#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

struct stDate
{
  int16_t Day;
  int16_t Month;
  int16_t Year;
};

uint16_t *DataPrompt(const char *Message)
{
  uint16_t *Number = new uint16_t;

  cout<<Message;
  cin>>*Number;

  return (Number);
}

stDate InsertDate()
{
  stDate Date;
  uint16_t *Day = DataPrompt("Enter a day: ");
  uint16_t *Month = DataPrompt("Enter a month: ");
  uint16_t *Year = DataPrompt("Enter a year: ");
  
  Date.Day = *Day;
  Date.Month = *Month;
  Date.Year = *Year;

  delete(Day);
  delete(Month);
  delete(Year);
  
  return (Date);
}

uint16_t DaysInYear(uint16_t Year)
{
  return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0 ? 366 : 365);
}

uint16_t FebCheck(uint16_t Year)
{
  return (DaysInYear(Year) == 366 ? 29 : 28);
}

uint16_t DaysInMonth(uint16_t Month, uint16_t Year)
{
  uint16_t arr[4] = {4, 6, 9, 11};
  
  if (Month == 1)
    return (31);

  return (Month == 2 ? FebCheck(Year) : Month == arr[uint16_t(round(Month / 3.0f) - 1)] ? 30 : 31);
}

int16_t TotalDays(uint16_t Day, uint16_t Month, uint16_t Year)
{
  int16_t TotalDays = Day;

  while (Month != 1) {
    TotalDays += DaysInMonth(--Month, Year);
  }
  
  return (TotalDays);
}

stDate DateGenerator(stDate Date)
{
  uint16_t i = 1;

  cout<<"Generator:\n";
  cout<<"Before Days: "<<Date.Day<<'\n';
  
  if (Date.Day < 0) {
    Date.Day *= -1;
    double counter = ceil((double)Date.Day / DaysInYear(Date.Year));
    cout<<"counter: "<<counter<<'\n';
    Date.Year -= counter;
    while (counter != 0) {
      Date.Day = abs(Date.Day - DaysInYear((Date.Year + 1) - --counter)); 
    }
    cout<<"Remaining Days: "<<Date.Day<<endl;
    if (Date.Day <= 31) {
      Date.Month = 1;
    } else {
      while (Date.Day > DaysInMonth(i, Date.Year)) {
	Date.Day -= DaysInMonth(++i, Date.Year);
	Date.Month = i;
      }
    }
  }
    
  if (Date.Day == 0) {
    if (Date.Month == 1) {
      Date.Month = 12;
      Date.Year--;
    } else {
      Date.Month--;
    }
    Date.Day = DaysInMonth(Date.Month, Date.Year);
  }

  i = Date.Month;
  
  while (Date.Day > DaysInMonth(i, Date.Year)) {
    Date.Day -= DaysInMonth(--i, Date.Year);
  }
 
  
  cout<<"After Days: "<<Date.Day<<'\n';
  return (Date);
}

stDate DecreaseOneDay(stDate Date)
{
  cout<<"TotalDays: "<<TotalDays(Date.Day, Date.Month, Date.Year)<<endl;
  Date.Day = TotalDays(Date.Day, Date.Month, Date.Year) - 1;
  cout<<"Days: "<<Date.Day<<'\n';
  
  Date = DateGenerator(Date);
  
  return (Date);
}

stDate DecreaseDateByXDays(stDate Date, uint16_t Days)
{
  cout<<"TotalDays: "<<TotalDays(Date.Day, Date.Month, Date.Year)<<endl;
  Date.Day = TotalDays(Date.Day, Date.Month, Date.Year) - Days;
  cout<<"Days by "<<Days<<": "<<Date.Day<<'\n';
  
  Date = DateGenerator(Date);
  
  return Date;
}

int main(void)
{
  stDate Date;
  uint16_t *Value = new uint16_t;
  
  Date = InsertDate();
  cout<<"Default Date: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;

  cout<<"Days in month(Default Date): "<<DaysInMonth(Date.Month, Date.Year)<<endl;
  
  Date = DecreaseOneDay(Date);
  cout<<"Decrease Date By 1 Day: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
  Value = DataPrompt("Enter amount of days to be decreased: ");
  
  Date = DecreaseDateByXDays(Date, *Value);
  cout<<"Decrease Date By "<<(*Value)<<" Days: "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<endl;
 
  return (0);
}
