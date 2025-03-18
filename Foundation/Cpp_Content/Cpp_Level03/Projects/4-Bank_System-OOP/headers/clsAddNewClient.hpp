#ifndef CLSADDNEWCLIENT_HPP
#define CLSADDNEWCLIENT_HPP

#include "clsscreen.hpp"

class clsAddNewClient : protected clsScreen
{
private:
  static void _ReadStr(clsBankClient &Client);
  static void _PrintClient(clsBankClient Client);
public:
  static void AddNewClient();
};

#endif /* CLSADDNEWCLIENT_HPP */
