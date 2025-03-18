#ifndef CLSWITHDRAWSCREEN_HPP
#define CLSWITHDRAWSCREEN_HPP

#include "clsTransactionsScreen.hpp"

class clsWithdrawScreen : protected clsScreen
{
private:
  static string _ReadAccNum(const char *Msg);
  static void _PrintClient(clsBankClient Client);
public:
  static void PerformWithdraw();
};

#endif /* CLSWITHDRAWSCREEN_HPP */
