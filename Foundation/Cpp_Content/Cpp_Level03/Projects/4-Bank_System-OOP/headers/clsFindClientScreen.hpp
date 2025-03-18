#ifndef CLSFINDCLIENTSCREEN_HPP
#define CLSFINDCLIENTSCREEN_HPP

#include "clsscreen.hpp"

class clsFindClientScreen : protected clsScreen
{
private:
  //static void _ReadStr(clsBankClient &Client);
  static void _PrintClient(clsBankClient Client);
public:
  static void FindClient();
};

#endif /* CLSFINDCLIENTSCREEN_HPP */
