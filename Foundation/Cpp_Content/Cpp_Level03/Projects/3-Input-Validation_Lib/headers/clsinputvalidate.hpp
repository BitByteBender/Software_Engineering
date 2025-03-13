#ifndef CLSINPUTVALIDATE_HPP
#define CLSINPUTVALIDATE_HPP

#include "clsdate.hpp"

using std::cin;
using std::cerr;
using std::ws;

class clsInputValidate
{
 public:
  static bool IsNumberBetween(int Num, int From, int To);
  static bool IsNumberBetween(double Num, double From, double To);
  static bool IsNumberBetween(float Num, float From, float To);
  static bool IsDateBetween(clsDate Date, clsDate From, clsDate To);
  static int ReadIntegerNumber(const char *Msg);
  static int ReadIntegerNumberBetween(int From, int To, const char *Msg);
  static bool NANChecker(string Str);
};

#endif /* CLSINPUTVALIDATE_HPP */
