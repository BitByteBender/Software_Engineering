#ifndef CLSCURRENCYCALCULATORSCREEN_HPP
#define CLSCURRENCYCALCULATORSCREEN_HPP

#include "clsscreen.hpp"

class clsCurrencyCalc : protected clsScreen
{
private:
  static double _ReadAmount();
  static clsCurrency _ReadTag();
  static void _PrintCardConverter(clsCurrency &CurrencyA, clsCurrency &CurrencyB, double &Amount, double &ConvertedAmount, string NewCur);
public:
  static void ShowCurrCalc();
};

#endif /* CLSCURRENCYCALCULATORSCREEN_HPP */
