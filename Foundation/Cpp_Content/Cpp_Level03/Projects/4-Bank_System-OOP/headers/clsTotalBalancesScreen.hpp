#ifndef CLSTOTALBALANCESSCREEN_HPP
#define CLSTOTALBALANCESSCREEN_HPP

#include "clsTransactionsScreen.hpp"

class clsTotalBalancesScreen : protected clsScreen
{
private:
  static void PrintBalancesRecordLine(clsBankClient Client);
  
public:
  static void ShowTotalBalances();
};

#endif /* CLSTOTALBALANCESSCREEN_HPP */
