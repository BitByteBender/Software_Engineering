#ifndef CLSMANAGEUSERSMENU_HPP
#define CLSMANAGEUSERSMENU_HPP

#include "clsscreen.hpp"

class clsManageUsersMenu : protected clsScreen
{
private:
  enum enUsrManagerMenuOptions
  {
    ListUsr = 1,
    AddNewUsr = 2,
    DeleteUsr = 3,
    UpdateUsr = 4,
    FindUsr = 5,
    MainMenu = 6,
  };
  
  static short _ReadManageUserMenuOption();
  static void _GoBackToUsrManagerMenu();
  static void _ShowListUsersScreen();
  static void _ShowAddNewUserScreen();
  static void _ShowDeleteUserScreen();
  static void _ShowUpdateUserScreen();
  static void _ShowFindUserScreen();
  static void _PerformManageUserMenu(enUsrManagerMenuOptions Option);
public:
  static void ShowManageUserScreen();
};
#endif /* CLSMANAGEUSERSMENU_HPP */
