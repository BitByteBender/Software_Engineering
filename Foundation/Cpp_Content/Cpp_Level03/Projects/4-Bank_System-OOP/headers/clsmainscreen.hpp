#ifndef CLSMAINSCREEN_HPP
#define CLSMAINSCREEN_HPP

#include "clsscreen.hpp"

class clsMainScreen : protected clsScreen
{
private:
  enum enMainMenuOptions
  {
    ClientsList = 1,
    InsertClient = 2,
    DeleteClient = 3,
    UpdateClient = 4,
    FindClient = 5,
    ShowTrxMenu = 6,
    ManageUsers = 7,
    LogFile = 8,
    CurrencyExchange = 9,
    Exit = 10,
  };

  static short _ReadMainMenuOption();
  static void _GoBackToMainMenu();
  static void _ShowAllClientsScreen();
  static void _ShowAddNewClientsScreen();
  static void _ShowDeleteClientScreen();
  static void _ShowUpdateClientScreen();
  static void _ShowFindClientScreen();
  static void _ShowTransactionsMenu();
  static void _ShowManageUsersMenu();
  static void _ShowLogFileScreen();
  static void _ShowCurrencyScreen();
  static void _Logout();
  static void _PerformMainMenuOption(enMainMenuOptions Option);

public:
  static void ShowMainMenu();
};

#endif /* CLSMAINSCREEN_HPP */
