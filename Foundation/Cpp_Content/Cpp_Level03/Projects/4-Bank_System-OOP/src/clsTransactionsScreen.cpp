#include "../headers/clsTransactionsScreen.hpp"
#include "../headers/clsDepositScreen.hpp"
#include "../headers/clsWithdrawScreen.hpp"
#include "../headers/clsTotalBalancesScreen.hpp"
#include "../headers/clsTransferScreen.hpp"
#include "../headers/clsTransferLogListScreen.hpp"

short clsTransactionsScreen::_ReadTrxMenuOption()
{
  int16_t Choice;
 
  cout<<setw(25)<<left<<""<<"Choose an option from the menu above [1 To 6]: ";
  Choice = clsInputValidate::ReadIntegerNumberBetween(1, 6, "Enter a number between 1 to 6: ");
  
  return (Choice);
}

void clsTransactionsScreen::_GoBacktoTrxMenu()
{
  cout<<setw(37)<<left<<"\n\tPress any key to go back to main menu...\n";
  cin.get();
  ShowTransactionsMenu();
}

void clsTransactionsScreen::_ShowDepositScreen()
{
  clsDepositScreen::PerformDeposit();
}

void clsTransactionsScreen::_ShowWithdrawScreen()
{
  clsWithdrawScreen::PerformWithdraw();
}

void clsTransactionsScreen::_ShowTotalBalancesScreen()
{
  clsTotalBalancesScreen::ShowTotalBalances();
}

void clsTransactionsScreen::_ShowTransferScreen()
{
  clsTransferScreen::Transfer();
}

void clsTransactionsScreen::_ShowTransferLogScreen()
{
  clsTransferLogList::ShowTransferLog();
}

void clsTransactionsScreen::_PerformTrxMenuOption(enTrxMenuOptions Option)
{
  switch (Option) {
  case (enTrxMenuOptions::Deposit):
    _ShowDepositScreen();
    _GoBacktoTrxMenu();
    break;
  case (enTrxMenuOptions::Withdraw):
    _ShowWithdrawScreen();
    _GoBacktoTrxMenu();
    break;
  case (enTrxMenuOptions::TotalBalances):
    _ShowTotalBalancesScreen();
    _GoBacktoTrxMenu();
    break;
  case (enTrxMenuOptions::Transfer):
    _ShowTransferScreen();
    _GoBacktoTrxMenu();
    break;
  case (enTrxMenuOptions::TransferLog):
    _ShowTransferLogScreen();
    _GoBacktoTrxMenu();
    break;
  case (enTrxMenuOptions::MainMenu):
    break;
  }
}

void clsTransactionsScreen::ShowTransactionsMenu()
{
  if (!_CheckAccessRights(clsUser::enPermissions::Trx))
      return ;
  _DrawScreenHeader("\t\tTransactions Screen");
  _ShowStats();
  
  cout<<setw(35)<<left<<""<<"======================================\n";
  cout<<setw(35)<<left<<""<<"\t\t  Transactions Menu\n";
  cout<<setw(35)<<left<<""<<"======================================\n";
  cout<<setw(35)<<left<<""<<"\t   [1] Deposit.\n";
  cout<<setw(35)<<left<<""<<"\t   [2] Withdraw.\n";
  cout<<setw(35)<<left<<""<<"\t   [3] Total Balances.\n";
  cout<<setw(35)<<left<<""<<"\t   [4] Transfer.\n";
  cout<<setw(35)<<left<<""<<"\t   [5] Transfer Log.\n";
  cout<<setw(35)<<left<<""<<"\t   [6] Main Menu.\n";
  cout<<setw(35)<<left<<""<<"======================================\n";

  _PerformTrxMenuOption((enTrxMenuOptions)_ReadTrxMenuOption());
}
