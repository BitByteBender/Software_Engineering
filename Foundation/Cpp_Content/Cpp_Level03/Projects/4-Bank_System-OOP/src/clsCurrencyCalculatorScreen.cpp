#include "../headers/clsCurrencyCalculatorScreen.hpp"

double clsCurrencyCalc::_ReadAmount()
{
  return (clsInputValidate::ReadDblNumber("Enter an amount to exchange: "));
}

clsCurrency clsCurrencyCalc::_ReadTag()
{
  clsCurrency Currency;
  string Choice = clsInputValidate::ReadString("Enter a Currency tag: ");

  while (!clsCurrency::IsCurrencyExist(Choice, "Tag"))
    Choice = clsInputValidate::ReadString("Failed! re-enter an available currency: ");

  Currency = clsCurrency::FindByTag(Choice);
  return (Currency);
}

void clsCurrencyCalc::_PrintCardConverter(clsCurrency &CurrencyA, clsCurrency &CurrencyB, double &Amount, double &ConvertedAmount, string NewCurr)
{
  cout<<"Convert From:\n"
      <<"_____________________________\n"
      <<"Country : "<<CurrencyA.GetCountry()<<'\n'
      <<"Tag     : "<<CurrencyA.GetCurrencyTag()<<'\n'
      <<"Name    : "<<CurrencyA.GetCurrencyName()<<'\n'
      <<"Rate    : "<<CurrencyA.GetCurrencyRate()<<'\n'
      <<"_____________________________\n\n";

  cout<<Amount<<' '<<CurrencyA.GetCurrencyTag()<<" = ";
  
  if (CurrencyA.GetCurrencyTag() == "USD" || CurrencyB.GetCurrencyTag() == "USD")
    cout<<ConvertedAmount<<' '<<NewCurr<<endl;
  else {
    cout<<(ConvertedAmount / CurrencyB.GetCurrencyRate())<<"USD\n"<<endl;
    
    cout<<"Convert From USD to:\n\n";
    cout<<"To:\n"
      <<"_____________________________\n"
      <<"Country : "<<CurrencyB.GetCountry()<<'\n'
      <<"Tag     : "<<CurrencyB.GetCurrencyTag()<<'\n'
      <<"Name    : "<<CurrencyB.GetCurrencyName()<<'\n'
      <<"Rate    : "<<CurrencyB.GetCurrencyRate()<<'\n'
      <<"_____________________________\n\n";

    cout<<Amount<<' '<<CurrencyA.GetCurrencyTag()<<" = "<<ConvertedAmount<<' '<<NewCurr<<endl;
  }
}

void clsCurrencyCalc::ShowCurrCalc()
{
  _DrawScreenHeader("\t\tCurrency Calculator");
  clsCurrency CurrencyA, CurrencyB;
  double Amount = 0.0, CalcAmount = 0.0;
  char Answer = 'n';
  
  do {
    CurrencyA = _ReadTag();
    CurrencyB = _ReadTag();
    
    Amount = _ReadAmount();
    CalcAmount = clsCurrency::CalcRate(Amount, CurrencyA.GetCurrencyTag(), CurrencyB.GetCurrencyTag());
    _PrintCardConverter(CurrencyA, CurrencyB, Amount, CalcAmount, CurrencyB.GetCurrencyTag());

    cout<<"Do you want to perform another calculation? (y/n): ";
    cin>>Answer;
    
  } while (Answer != 'n' && Answer != 'N');
}
