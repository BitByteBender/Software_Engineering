#ifndef CLSDELETECLIENTSCREEN_HPP
#define CLSDELETECLIENTSCREEN_HPP

#include "clsscreen.hpp"

class clsDeleteClientScreen : protected clsScreen
{
private:
  static void _ReadStr(clsBankClient &Client);
  static void _PrintClient(clsBankClient Client);
public:
  static void DeleteClient();
};

#endif /* CLSDELETECLIENTSCREEN_HPP */
