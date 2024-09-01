#include <iostream>
#include <string>

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

uint16_t *ReadNum(const char *Message)
{
  uint16_t *ptrNum = new uint16_t;

  cout<<Message;
  cin>>*ptrNum;
  
  return (ptrNum);
}

/*
void FreeMemo(uint16_t *ptrNum)
{
  uint16_t i = 1;
  
  for (; i <= 3; ++i)
    delete ptrNum;
}
*/

stDate SaveDateRecord()
{
  stDate Date;
  uint16_t *ptrNum = nullptr;

  ptrNum = ReadNum("Enter a day: ");
  Date.Day = *ptrNum;
  delete ptrNum;
  
  ptrNum = ReadNum("Enter a month: ");
  Date.Month = *ptrNum;
  delete ptrNum;
  
  ptrNum = ReadNum("Enter a year: ");
  Date.Year = *ptrNum;
  delete ptrNum;

  return (Date);
}

inline uint16_t isLeapYear(uint16_t Year)
{
  return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0? 366 : 365);
}

inline uint16_t FebCheck(uint16_t Year)
{
  return (isLeapYear(Year) != 366 ? 28 : 29);
}

uint16_t getDaysInMonth(uint16_t Month, uint16_t Year)
{
  uint16_t arr[7] = {1, 3, 5, 7, 8, 10, 12};

  return (Month == 2 ? FebCheck(Year) : Month == arr[Month/2] ? 31 : 30);
}

inline bool ValidateDate(stDate Date)
{
  return (Date.Year > 0 && (Date.Month <= 12 && Date.Month > 0) && (Date.Day <= getDaysInMonth(Date.Month, Date.Year) && Date.Day > 0));
}

void DisplayResult(stDate Date)
{
  if (ValidateDate(Date)) cout<<"Yes, Date is a valide date"<<endl;
  else cout<<"No, Date is NOT a valid date"<<endl;
}

int main(void)
{
  stDate Date;

  Date = SaveDateRecord();

  DisplayResult(Date);
  
  return (0);
}
