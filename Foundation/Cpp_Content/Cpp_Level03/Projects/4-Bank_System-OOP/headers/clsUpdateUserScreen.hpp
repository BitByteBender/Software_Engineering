#ifndef CLSUPDATEUSERSCREEN_HPP
#define CLSUPDATEUSERSCREEN_HPP

#include "clsscreen.hpp"
#include "clsUser.hpp"

class clsUpdateUser : protected clsScreen
{
private:
  static void _ReadStr(clsUser &User);
  static void _PrintUser(clsUser User);
  static int16_t _ReadPermissionsToSet();
public:
  static void UpdateUser();
};

#endif /* CLSUPDATEUSERSCREEN_HPP */
