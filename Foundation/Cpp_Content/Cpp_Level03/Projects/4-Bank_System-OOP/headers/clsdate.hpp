#ifndef CLSDATE_H
#define CLSDATE_H

#include "clsmisc.hpp"
#include <ctime>

class clsDate : public clsMisc
{
private:
  string m_Day, m_Month, m_Year;

public:
  clsDate();
  clsDate(string &DateFormat);
  clsDate(uint16_t &Day, uint16_t &Month, uint16_t &Year);
  clsDate(uint16_t &Days, uint16_t &Year);

  void setDay(string &Day);
  void setMonth(string &Month);
  void setYear(string &year);

  string getDay() const;
  string getMonth() const;
  string getYear() const;
  
  static uint16_t isLeap(uint16_t Year);
  uint16_t isLeap();
  
  static uint16_t getFebDays(uint16_t Year);
  uint16_t getFebDays();

  static uint16_t getDaysInMonth(uint16_t Month, uint16_t Year);
  uint16_t getDaysInMonth() const;

  static uint16_t DaysIntoMonths(uint16_t Days, uint16_t Year);
  uint16_t DaysIntoMonths() const;
  
  static uint16_t RemainingDays(uint16_t Days, uint16_t Year);
  uint16_t RemainingDays() const;

  static uint16_t GregorianCalc(clsDate *Date);
  //static uint16_t GregorianCalc(clsDate Date);
  uint16_t GregorianCalc();

  static bool IsValid(clsDate *Date);
  bool IsValid();

  static string DateToString(clsDate Date);
  string DateToString() const;

  static bool IsDateBetween(clsDate Date, clsDate From, clsDate To);
  bool IsDateBetween() const;

  static string GetClockTime();
  void Print() const;
  
  ~clsDate();
};

#endif /* CLSDATE_H */
