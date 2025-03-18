#ifndef CLSADDNEWUSER_HPP
#define CLSADDNEWUSER_HPP

#include "clsscreen.hpp"
#include "clsUser.hpp"

class clsAddNewUser : protected clsScreen
{
private:
  static void _ReadStr(clsUser &User);
  static void _PrintUser(clsUser User);
  static int16_t _ReadPermissionsToSet();
  
public:
  static void AddNewUser();
};

#endif /* CLSADDNEWCLIENT_HPP */
