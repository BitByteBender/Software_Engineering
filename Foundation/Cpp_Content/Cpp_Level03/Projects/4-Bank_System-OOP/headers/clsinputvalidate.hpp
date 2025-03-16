#ifndef CLSINPUTVALIDATE_HPP
#define CLSINPUTVALIDATE_HPP

#include "clsdate.hpp"
#include "clsString.hpp"

using std::cin;
using std::cerr;
using std::ws;
using std::numeric_limits;
using std::streamsize;

class clsInputValidate
{
 public:
  static bool IsNumberBetween(int Num, int From, int To);
  static bool IsNumberBetween(double Num, double From, double To);
  static bool IsNumberBetween(float Num, float From, float To);
  static bool IsDateBetween(clsDate Date, clsDate From, clsDate To);
  static int ReadIntegerNumber(const char *Msg);
  static int ReadIntegerNumber(string Msg="Invalid number, Enter again: ");
  static bool NANChecker(string Str);
  static int ReadIntegerNumberBetween(int From, int To, const char *Msg);
  static double ReadDblNumber(const char *Msg);
  static double ReadDoubleNumber(const char *Msg="Invalid number, Enter again: ");
  static double ReadDblNumberBetween(double From, double To, const char *Msg);
  static bool IsValidDate(clsDate Date);
  static string ReadString(const char *Msg);
  /*
  static clsBankClient ReadObj(string AccNum, bool Trigger=false);
  static bool IsValid();
  */
};

#endif /* CLSINPUTVALIDATE_HPP */
