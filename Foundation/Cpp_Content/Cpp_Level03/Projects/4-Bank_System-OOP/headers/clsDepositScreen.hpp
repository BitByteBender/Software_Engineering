#ifndef CLSDEPOSITSCREEN_HPP
#define CLSDEPOSITSCREEN_HPP

#include "clsTransactionsScreen.hpp"

class clsDepositScreen : protected clsScreen
{
private:
  static string _ReadAccNum(const char *Msg);
  static void _PrintClient(clsBankClient Client);
public:
  static void PerformDeposit();
};

#endif /* CLSDEPOSITSCREEN_HPP */
