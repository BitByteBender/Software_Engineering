#ifndef CLSLOGINSCREEN_HPP
#define CLSLOGINSCREEN_HPP

#include "clsscreen.hpp"

class clsLoginScreen : protected clsScreen
{
private:
  static void _Login();
public:
  static void ShowLoginScreen();
};

#endif /* CLSLOGINSCREEN_HPP */
