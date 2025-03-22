#ifndef CLSTRANSFERLOGLISTSCREEN_HPP
#define CLSTRANSFERLOGLISTSCREEN_HPP

#include "clsscreen.hpp"

class clsTransferLogList : protected clsScreen
{
private:
  static void _PrintTransferLog(clsBankClient::TransferType &Tl);
public:
  static void ShowTransferLog();
};
#endif /* CLSTRANSFERLOGLISTSCREEN_HPP */
