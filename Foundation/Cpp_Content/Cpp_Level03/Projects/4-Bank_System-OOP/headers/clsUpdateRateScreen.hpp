#ifndef CLSUPDATERATESCREEN_HPP
#define CLSUPDATERATESCREEN_HPP

#include "clsscreen.hpp"

class clsUpdateRate : protected clsScreen
{
private:
  static clsCurrency _LoadCurrencyData();
  static void _PrintCurrency(clsCurrency &Currency);
  
public:
  static void ShowUpdate();
};

#endif /* CLSUPDATERATESCREEN_HPP */
