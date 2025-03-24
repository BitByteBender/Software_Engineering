#ifndef CLSCURRENCYSCREEN_HPP
#define CLSCURRENCYSCREEN_HPP

#include "clsscreen.hpp"

class clsCurrencyScreen : protected clsScreen
{
private:
  enum enCurrencyMenu{
    ListCurrency = 1, FindCurrency = 2,
    UpdateRate = 3, CurrencyCalc = 4, MainMenu = 5
  };
    
  static short _ReadChoice();
  static void _ShowListCurrenciesScreen();
  static void _ShowFindCurrencyScreen();
  static void _ShowUpdateRateScreen();
  static void _ShowCurrencyCalcScreen();
  static void _GoBackToCurrencyScreen();
  static void _GetCurrencyMenuChoice(enCurrencyMenu Choice);
public:
  static void ShowCurrencyScreen();
};
#endif /* CLSCURRENCYSCREEN_HPP */
