#include "../headers/clsmainscreen.hpp"
#include "../headers/clsClientListScreen.hpp"
#include "../headers/clsAddNewClient.hpp"
#include "../headers/clsDeleteClientScreen.hpp"
#include "../headers/clsUpdateClientScreen.hpp"
#include "../headers/clsFindClientScreen.hpp"
#include "../headers/clsTransactionsScreen.hpp"
#include "../headers/clsManageUsersMenu.hpp"
#include "../headers/clsLogFileScreen.hpp"
#include "../headers/global.hpp"
#include "../headers/clsCurrencyScreen.hpp"

short clsMainScreen::_ReadMainMenuOption()
{
  int16_t Choice;
 
  cout<<setw(25)<<left<<""<<"Choose an option from the menu above [1 To 10]: ";
  Choice = clsInputValidate::ReadIntegerNumberBetween(1, 10, "Enter a number between 1 to 10? ");
  
  return (Choice);
}

void clsMainScreen::_GoBackToMainMenu()
{
  cout<<setw(37)<<left<<"\n\tPress any key to go back to main menu...\n";
  cin.get();
  ShowMainMenu();
}

void clsMainScreen::_ShowAllClientsScreen()
{
  clsClientListScreen::ShowClientsList();
}

void clsMainScreen::_ShowAddNewClientsScreen()
{
  clsAddNewClient::AddNewClient();
}

void clsMainScreen::_ShowDeleteClientScreen()
{
  clsDeleteClientScreen::DeleteClient();
}

void clsMainScreen::_ShowUpdateClientScreen()
{
  clsUpdateClientScreen::UpdateClient();
}

void clsMainScreen::_ShowFindClientScreen()
{
  clsFindClientScreen::FindClient();
}

void clsMainScreen::_ShowTransactionsMenu()
{
  clsTransactionsScreen::ShowTransactionsMenu();
}

void clsMainScreen::_ShowManageUsersMenu()
{
  clsManageUsersMenu::ShowManageUserScreen();
}

void clsMainScreen::_ShowLogFileScreen()
{
  clsLogFileScreen::ShowLogFileList();
}

void clsMainScreen::_ShowCurrencyScreen()
{
  clsCurrencyScreen::ShowCurrencyScreen();
}

void clsMainScreen::_Logout()
{
  //exit(EXIT_SUCCESS);
  CurrentUser = clsUser::Find("", "");
}

void clsMainScreen::_PerformMainMenuOption(enMainMenuOptions Option)
{
  switch (Option) {
  case (enMainMenuOptions::ClientsList):
    _ShowAllClientsScreen();
    _GoBackToMainMenu();
    break;
  case (enMainMenuOptions::InsertClient):
    _ShowAddNewClientsScreen();
    _GoBackToMainMenu();
    break;
  case (enMainMenuOptions::DeleteClient):
    _ShowDeleteClientScreen();
    _GoBackToMainMenu();
    break;
  case (enMainMenuOptions::UpdateClient):
    _ShowUpdateClientScreen();
    _GoBackToMainMenu();
    break;
  case (enMainMenuOptions::FindClient):
    _ShowFindClientScreen();
    _GoBackToMainMenu();
    break;
  case (enMainMenuOptions::ShowTrxMenu):
    _ShowTransactionsMenu();
    _GoBackToMainMenu();
    break;
  case (enMainMenuOptions::ManageUsers):
    _ShowManageUsersMenu();
    _GoBackToMainMenu();
    break;
  case (enMainMenuOptions::LogFile):
    _ShowLogFileScreen();
    _GoBackToMainMenu();
    break;
  case (enMainMenuOptions::CurrencyExchange):
    _ShowCurrencyScreen();
    _GoBackToMainMenu();
    break;
  case (enMainMenuOptions::Exit):
    _Logout();
    //Login();
    break;
  }
}

void clsMainScreen::ShowMainMenu()
{
  _DrawScreenHeader("\t\tMain Screen");
  _ShowStats();
  cout<<setw(35)<<left<<""<<"======================================\n";
  cout<<setw(35)<<left<<""<<"\t\t  Main Menu\n";
  cout<<setw(35)<<left<<""<<"======================================\n";
  cout<<setw(35)<<left<<""<<"\t   [1] Show Client List.\n";
  cout<<setw(35)<<left<<""<<"\t   [2] Add New Client.\n";
  cout<<setw(35)<<left<<""<<"\t   [3] Delete Client.\n";
  cout<<setw(35)<<left<<""<<"\t   [4] Update Client Info.\n";
  cout<<setw(35)<<left<<""<<"\t   [5] Find Client.\n";
  cout<<setw(35)<<left<<""<<"\t   [6] Transactions.\n";
  cout<<setw(35)<<left<<""<<"\t   [7] Manage Users.\n";
  cout<<setw(35)<<left<<""<<"\t   [8] Log File.\n";
  cout<<setw(35)<<left<<""<<"\t   [9] Currency Exchange.\n";
  cout<<setw(35)<<left<<""<<"\t   [10] Logout.\n";
  cout<<setw(35)<<left<<""<<"======================================\n";

  _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
}
