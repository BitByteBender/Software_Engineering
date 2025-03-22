#ifndef CLSTRANSFERSCREEN_HPP
#define CLSTRANSFERSCREEN_HPP

#include "clsscreen.hpp"

class clsTransferScreen : protected clsScreen
{
private:
  static clsBankClient _GetUserByAccNum(const char *Msg);
  static void _PrintUserCardInfo(clsBankClient &Client);
  static bool _IsAccNum(string AccNum);
  static double _ReadAmount(clsBankClient &Client);
public:
  static void Transfer();
};

#endif /* CLSTRANSFERSCREEN_HPP */
