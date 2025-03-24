#include "../headers/clsUpdateRateScreen.hpp"

clsCurrency clsUpdateRate::_LoadCurrencyData()
{
  clsCurrency Currency;
  
  string Tag = clsInputValidate::ReadString("Enter a currency tag: ");
  
  while (!clsCurrency::IsCurrencyExist(Tag))
    Tag = clsInputValidate::ReadString("Failed! re-enter a Currency tag: ");

  Currency = clsCurrency::FindByTag(Tag);
  return (Currency);
}

void clsUpdateRate::_PrintCurrency(clsCurrency &Currency)
{
  cout<<"| "<<clsUtil::SmartSpacer(Currency.GetCountry(), 30)
      <<"| "<<clsUtil::SmartSpacer(Currency.GetCurrencyName(), 30)
      <<"| "<<clsUtil::SmartSpacer(Currency.GetCurrencyTag(), 23)
      <<"| "<<clsUtil::SmartSpacer(to_string(Currency.GetCurrencyRate()), 17)
      <<endl;
}

void clsUpdateRate::ShowUpdate()
{
  clsCurrency Currency;
  char Answer = 'n';
  double Rate = 0.0;
  
  _DrawScreenHeader("\t\tUpdate Rate");

  Currency = _LoadCurrencyData();
  _PrintCurrency(Currency);

  cout<<"\nDo you want to update the rate(y/n): ";
  cin>>Answer;

  if (Answer == 'y' || Answer == 'Y') {
    Rate = clsInputValidate::ReadDblNumber("Enter a new rate: ");
    Currency.Update(Rate);
    _PrintCurrency(Currency);
  } else cout<<"Operation has been Terminated\n";
}
