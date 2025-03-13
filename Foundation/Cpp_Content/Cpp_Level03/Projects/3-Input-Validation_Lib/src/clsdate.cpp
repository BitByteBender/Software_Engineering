#include "../headers/clsdate.hpp"

clsDate::clsDate()
{
  time_t t = time(0);
  tm *now = localtime(&t);
  
  this->m_Day = to_string(now->tm_mday);
  this->m_Month = to_string(now->tm_mon + 1);
  this->m_Year = to_string(now->tm_year + 1900);
}

clsDate::clsDate(string &DateFormat)
{
  this->m_Day = to_string(clsMisc::SplitAdv(DateFormat)[0]);
  this->m_Month = to_string(clsMisc::SplitAdv(DateFormat)[1]);
  this->m_Year = to_string(clsMisc::SplitAdv(DateFormat)[2]);
}

clsDate::clsDate(uint16_t &Day, uint16_t &Month, uint16_t &Year)
  : m_Day(to_string(Day)), m_Month(to_string(Month)), m_Year(to_string(Year)) {}

clsDate::clsDate(uint16_t &Days, uint16_t &Year)
{
  this->m_Day = to_string(clsDate::RemainingDays(Days, Year));
  this->m_Month = to_string(clsDate::DaysIntoMonths(Days, Year));
  this->m_Year = to_string(Year);
}

void clsDate::setDay(string &Day)
{
  this->m_Day = Day;
}

string clsDate::getDay() const
{
  return (m_Day);
}

void clsDate::setMonth(string &Month)
{
  this->m_Month = Month;
}

string clsDate::getMonth() const
{
  return (m_Month);
}

void clsDate::setYear(string &Year)
{
  this->m_Year = Year;
}

string clsDate::getYear() const
{
  return (m_Year);
}

uint16_t clsDate::isLeap(uint16_t Year)
{
  return ((Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0)) ? 366 : 365);
}

uint16_t clsDate::isLeap()
{
  return (isLeap(stoi(m_Year)));
}

uint16_t clsDate::getFebDays(uint16_t Year)
{
  return (isLeap(Year) == 366 ? 29 : 28);
}

uint16_t clsDate::getFebDays()
{
  return (getFebDays(stoi(m_Year)));
}

uint16_t clsDate::getDaysInMonth(uint16_t Month, uint16_t Year)
{
  uint16_t MonthArr[7] = {1, 3, 5, 7, 8, 10, 12};

  return (Month == 2 ? getFebDays(Year) : ((MonthArr[uint16_t(Month/2)] == Month) ? 31 : 30));
}

uint16_t clsDate::getDaysInMonth() const
{
  return (getDaysInMonth(stoi(m_Month), stoi(m_Year)));
}

uint16_t clsDate::DaysIntoMonths(uint16_t Days, uint16_t Year)
{
  uint16_t Month = 1;

  while (Days > getDaysInMonth(Month, Year)) {
    Days -= getDaysInMonth(Month, Year);
    Month++;
  }

  return (Month);
}

uint16_t clsDate::DaysIntoMonths() const
{
  return (DaysIntoMonths(stoi(m_Day), stoi(m_Year)));
}

uint16_t clsDate::RemainingDays(uint16_t Days, uint16_t Year)
{
  uint16_t i = 1;
  
  while (Days > getDaysInMonth(i, Year)) {
    Days -= getDaysInMonth(i, Year);
    i++;
  }
  
  return (Days);
}

uint16_t clsDate::RemainingDays() const
{
  return (RemainingDays(stoi(m_Day), stoi(m_Year)));
}

void clsDate::Print() const
{
  cout<<"Date <"<<m_Day<<'/'<<m_Month<<'/'<<m_Year<<">\n";
}

uint16_t clsDate::GregorianCalc(clsDate *Date)
{
  uint16_t a = 0, y = stoi(Date->m_Year), m = stoi(Date->m_Month), d = 0;

  a = floor((14 - m) / 12);
  y -= a;
  m += (12 * a) - 2;

  d = (stoi(Date->m_Day) + y + floor(y/4) - floor(y/100) + floor(y/400) + floor((31 * m) / 12));
  d = d % 7;

  return (d);
}
/*
uint16_t clsDate::GregorianCalc(clsDate Date)
{
  uint16_t a = 0, y = stoi(Date.m_Year), m = stoi(Date.m_Month), d = 0;

  a = floor((14 - m) / 12);
  y -= a;
  m += (12 * a) - 2;

  d = (stoi(Date.m_Day) + y + floor(y/4) - floor(y/100) + floor(y/400) + floor((31 * m) / 12));
  d = d % 7;

  return (d);
}
*/
uint16_t clsDate::GregorianCalc()
{
  return (GregorianCalc(this));
}

bool clsDate::IsValid(clsDate *Date)
{
  if (stoi(Date->m_Day) > getDaysInMonth(stoi(Date->m_Month), stoi(Date->m_Year)) || (stoi(Date->m_Month) > 12 || stoi(Date->m_Month) < 1)) return (0);
  else
    return (1);
}

bool clsDate::IsValid()
{
  return (IsValid(this));
}

string clsDate::DateToString(clsDate Date)
{
  return (Date.getDay() + '/' + Date.getMonth() + '/' + Date.getYear());
}

string clsDate::DateToString() const
{
  return (DateToString(*this));
}

clsDate::~clsDate()
{
}
