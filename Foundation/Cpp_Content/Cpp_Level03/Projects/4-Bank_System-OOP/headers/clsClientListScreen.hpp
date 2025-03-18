#ifndef CLSCLIENTLISTSCREEN_HPP
#define CLSCLIENTLISTSCREEN_HPP

#include "clsscreen.hpp"

class clsClientListScreen : protected clsScreen
{
private:
  static void PrintClientRecordLine(clsBankClient Client);
  
public:
  static void ShowClientsList();
};

#endif /* CLSCLIENTLISTSCREEN_HPP */
