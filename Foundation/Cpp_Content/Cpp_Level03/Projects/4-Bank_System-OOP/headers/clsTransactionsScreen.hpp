#ifndef CLSTRANSACTIONSSCREEN_HPP
#define CLSTRANSACTIONSSCREEN_HPP

#include "clsmainscreen.hpp"

class clsTransactionsScreen : protected clsScreen
{
private:
  enum enTrxMenuOptions
  {
    Deposit = 1,
    Withdraw = 2,
    TotalBalances = 3,
    Transfer = 4,
    TransferLog = 5,
    MainMenu = 6,
  };

  static short _ReadTrxMenuOption();
  static void _GoBacktoTrxMenu();
  static void _ShowDepositScreen();
  static void _ShowWithdrawScreen();
  static void _ShowTotalBalancesScreen();
  static void _ShowTransferScreen();
  static void _ShowTransferLogScreen();
  static void _PerformTrxMenuOption(enTrxMenuOptions Option);
  
public:
  static void ShowTransactionsMenu();
};
#endif /* CLSTRANSACTIONSSCREEN_HPP */
