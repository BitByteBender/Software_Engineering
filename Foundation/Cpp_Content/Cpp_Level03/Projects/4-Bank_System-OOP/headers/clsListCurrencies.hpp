#ifndef CLSLISTCURRENCIES_HPP
#define CLSLISTCURRENCIES_HPP

#include "clsscreen.hpp"

class clsListCurrencies : protected clsScreen
{
private:
  static void _PrintListCurrencies(clsCurrency &Currency);
public:
  static void ShowListCurrencies();
};

#endif /* CLSLISTCURRENCIES_HPP */
