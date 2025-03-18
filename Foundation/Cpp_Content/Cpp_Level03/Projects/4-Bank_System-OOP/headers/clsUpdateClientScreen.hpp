#ifndef CLSUPDATECLIENTSCREEN_HPP
#define CLSUPDATECLIENTSCREEN_HPP

#include "clsscreen.hpp"

class clsUpdateClientScreen : protected clsScreen
{
private:
  static void _ReadStr(clsBankClient &Client);
  static void _PrintClient(clsBankClient Client);
public:
  static void UpdateClient();
};

#endif /* CLSUPDATECLIENTSCREEN_HPP */
