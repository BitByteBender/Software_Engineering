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
    Exit = 8,
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
  static void _ShowEndScreen();
  static void _PerformMainMenuOption(enMainMenuOptions Option);
public:
  static void ShowMainMenu();
};

#endif /* CLSMAINSCREEN_HPP */
