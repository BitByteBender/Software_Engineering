#ifndef CLSLISTUSERSSCREEN_HPP
#define CLSLISTUSERSSCREEN_HPP

#include "clsscreen.hpp"
#include "clsUser.hpp"

class clsListUsersScreen : protected clsScreen
{
private:
  static void _PrintUserRecordLine(clsUser User);
public:
  static void ShowUsersList();
};

#endif /* CLSLISTUSERSSCREEN_HPP */
