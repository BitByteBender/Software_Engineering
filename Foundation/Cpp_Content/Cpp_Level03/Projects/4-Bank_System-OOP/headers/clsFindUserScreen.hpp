#ifndef CLSFINDUSERSCREEN_HPP
#define CLSFINDUSERSCREEN_HPP

#include "clsscreen.hpp"
#include "clsUser.hpp"

class clsFindUser : protected clsScreen
{
private:
  static void _PrintUser(clsUser User);
public:
  static void FindUser();
};

#endif /* CLSFINDUSERSCREEN_HPP */
