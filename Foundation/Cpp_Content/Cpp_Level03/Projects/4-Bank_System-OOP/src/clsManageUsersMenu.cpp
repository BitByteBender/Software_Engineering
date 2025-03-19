#include "../headers/clsManageUsersMenu.hpp"
#include "../headers/clsListUsersScreen.hpp"
#include "../headers/clsAddNewUsers.hpp"
#include "../headers/clsDeleteUserScreen.hpp"
#include "../headers/clsUpdateUserScreen.hpp"
#include "../headers/clsFindUserScreen.hpp"

short clsManageUsersMenu::_ReadManageUserMenuOption()
{
  int16_t Choice;
 
  cout<<setw(25)<<left<<""<<"Choose an option from the menu above [1 To 6]: ";
  Choice = clsInputValidate::ReadIntegerNumberBetween(1, 6, "Enter a number between 1 to 6: ");
  
  return (Choice);
}

void clsManageUsersMenu::_GoBackToUsrManagerMenu()
{
  cout<<setw(37)<<left<<"\n\tPress any key to go back to main menu...\n";
  cin.get();
  ShowManageUserScreen();
}

void clsManageUsersMenu::_ShowListUsersScreen()
{
  clsListUsersScreen::ShowUsersList();
}

void clsManageUsersMenu::_ShowAddNewUserScreen()
{
  clsAddNewUser::AddNewUser();
}

void clsManageUsersMenu::_ShowDeleteUserScreen()
{
  clsDeleteUser::DeleteUser();
}

void clsManageUsersMenu::_ShowUpdateUserScreen()
{
  clsUpdateUser::UpdateUser();
}

void clsManageUsersMenu::_ShowFindUserScreen()
{
  clsFindUser::FindUser();
}

void clsManageUsersMenu::_PerformManageUserMenu(enUsrManagerMenuOptions Option)
{
  switch (Option) {
  case (enUsrManagerMenuOptions::ListUsr):
    _ShowListUsersScreen();
    _GoBackToUsrManagerMenu();
    break;
  case (enUsrManagerMenuOptions::AddNewUsr):
    _ShowAddNewUserScreen();
    _GoBackToUsrManagerMenu();
    break;
  case (enUsrManagerMenuOptions::DeleteUsr):
    _ShowDeleteUserScreen();
    _GoBackToUsrManagerMenu();
    break;
  case (enUsrManagerMenuOptions::UpdateUsr):
    _ShowUpdateUserScreen();
    _GoBackToUsrManagerMenu();
    break;
  case (enUsrManagerMenuOptions::FindUsr):
    _ShowFindUserScreen();
    _GoBackToUsrManagerMenu();
    break;
  case (enUsrManagerMenuOptions::MainMenu):
    break;
  }
}

void clsManageUsersMenu::ShowManageUserScreen()
{
  if (!_CheckAccessRights(clsUser::enPermissions::ManageUsers))
      return ;
  _DrawScreenHeader("\t\tManage Users Screen");

  cout<<setw(35)<<left<<""<<"======================================\n";
  cout<<setw(35)<<left<<""<<"\t  Manage Users Menu\n";
  cout<<setw(35)<<left<<""<<"======================================\n";
  cout<<setw(35)<<left<<""<<"\t   [1] List Users.\n";
  cout<<setw(35)<<left<<""<<"\t   [2] Add New User.\n";
  cout<<setw(35)<<left<<""<<"\t   [3] Delete User.\n";
  cout<<setw(35)<<left<<""<<"\t   [4] Update User.\n";
  cout<<setw(35)<<left<<""<<"\t   [5] Find User.\n";
  cout<<setw(35)<<left<<""<<"\t   [6] Main Menu.\n";
  cout<<setw(35)<<left<<""<<"======================================\n";

  _PerformManageUserMenu((enUsrManagerMenuOptions)_ReadManageUserMenuOption());
}
