#ifndef CLSDELETEUSERSCREEN_HPP
#define CLSDELETEUSERSCREEN_HPP

#include "clsscreen.hpp"
#include "clsUser.hpp"

class clsDeleteUser : protected clsScreen
{
private:
  static void _ReadStr(clsUser &User);
  static void _PrintUser(clsUser User);
public:
  static void DeleteUser();
};

#endif /* CLSDELETEUSERSCREEN_HPP */
