#include "headers/core.hpp"
//#include "headers/clsmainscreen.hpp"
#include "headers/clsLoginScreen.hpp"

int main(void)
{
  //UpdateClient();
  //AddNewClient();
  //DeleteClient();
  // ShowClientsList();
  //ShowClientsTotalBalancesList();
  //clsMainScreen::ShowMainMenu();
  while (true)
    clsLoginScreen::ShowLoginScreen();
  
  return (0);
}
