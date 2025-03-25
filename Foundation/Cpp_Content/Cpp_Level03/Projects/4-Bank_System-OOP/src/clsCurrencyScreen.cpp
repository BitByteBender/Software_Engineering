#include "../headers/clsCurrencyScreen.hpp"
#include "../headers/clsFindScreen.hpp"
#include "../headers/clsListCurrencies.hpp"
#include "../headers/clsUpdateRateScreen.hpp"
#include "../headers/global.hpp"
#include "../headers/clsCurrencyCalculatorScreen.hpp"

short clsCurrencyScreen::_ReadChoice()
{
  uint16_t Choice = 0;

  cout<<setw(25)<<left<<""<<"Choose an option from the menu above [1 To 5]: ";
  Choice = clsInputValidate::ReadIntegerNumberBetween(1, 5, "Enter a choice between 1 and 5: ");

  return (Choice);
}

void clsCurrencyScreen::_ShowListCurrenciesScreen()
{
  clsListCurrencies::ShowListCurrencies();
}

void clsCurrencyScreen::_ShowUpdateRateScreen()
{
  clsUpdateRate::ShowUpdate();
}

void clsCurrencyScreen::_ShowFindCurrencyScreen()
{
  clsFindScreen::Find();
}

void clsCurrencyScreen::_ShowCurrencyCalcScreen()
{
  clsCurrencyCalc::ShowCurrCalc();
}

void clsCurrencyScreen::_GoBackToCurrencyScreen()
{
  cout<<"Press enter to go back to currency screen ...\n";
  cin.get();
  ShowCurrencyScreen();
}

void clsCurrencyScreen::_GetCurrencyMenuChoice(enCurrencyMenu Choice)
{
  switch (Choice) {
  case (enCurrencyMenu::ListCurrency):
    _ShowListCurrenciesScreen();
    _GoBackToCurrencyScreen();
    break;
  case (enCurrencyMenu::FindCurrency):
    _ShowFindCurrencyScreen();
    _GoBackToCurrencyScreen();
    break;
  case (enCurrencyMenu::UpdateRate):
    _ShowUpdateRateScreen();
    _GoBackToCurrencyScreen();
    break;
  case (enCurrencyMenu::CurrencyCalc):
    _ShowCurrencyCalcScreen();
    _GoBackToCurrencyScreen();
    break;
  case (enCurrencyMenu::MainMenu):
    break;
  }
}

void clsCurrencyScreen::ShowCurrencyScreen()
{
  if (!CurrentUser.CheckAccessPermission(clsUser::enPermissions::CurrencyExchange))
    return;
  
  _DrawScreenHeader("\t\tCurrency Exchange Main Screen");
  _ShowStats();

  cout<<setw(35)<<left<<""<<"======================================\n";
  cout<<setw(35)<<left<<""<<"\t   Currency Exchange Menu\n";
  cout<<setw(35)<<left<<""<<"======================================\n";
  cout<<setw(35)<<left<<""<<"\t   [1] List Currencies.\n";
  cout<<setw(35)<<left<<""<<"\t   [2] Find Currency.\n";
  cout<<setw(35)<<left<<""<<"\t   [3] Update Rate.\n";
  cout<<setw(35)<<left<<""<<"\t   [4] Currency Calc.\n";
  cout<<setw(35)<<left<<""<<"\t   [5] Main Menu.\n";
  cout<<setw(35)<<left<<""<<"======================================\n";
  
  _GetCurrencyMenuChoice((enCurrencyMenu) _ReadChoice());
}
