#ifndef CLSLOGFILESCREEN_HPP
#define CLSLOGFILESCREEN_HPP

#include "clsscreen.hpp"

class clsLogFileScreen : protected clsScreen
{
private:
  static void PrintRecord(clsUser::stUserLog UL);
public:
  static void ShowLogFileList();
};

#endif /* CLSLOGFILESCREEN_HPP */
