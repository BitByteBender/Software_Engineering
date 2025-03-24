#ifndef CLSFINDSCREEN_HPP
#define CLSFINDSCREEN_HPP

#include "clsscreen.hpp"

class clsFindScreen : protected clsScreen
{
private:
  static string _GetChoice();
  static void _PrintCurrencyRecord(clsCurrency &Currency);
  
public:
  static void Find();
};
#endif /* CLSFINDSCREEN_HPP */
