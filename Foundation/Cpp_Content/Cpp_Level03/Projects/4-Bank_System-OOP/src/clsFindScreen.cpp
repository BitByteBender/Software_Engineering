#include "../headers/clsFindScreen.hpp"

string clsFindScreen::_GetChoice()
{
  uint16_t Choice = clsInputValidate::ReadIntegerNumberBetween(1,2, "Enter [1] for Tag Or [2] for Country: ");

  return (Choice == 1 ? "Tag" : "Country");
}

void clsFindScreen::_PrintCurrencyRecord(clsCurrency &Currency)
{
  cout<<"Currency Card:\n"
      <<"__________________________________________________\n"
      <<"Country        : "<<Currency.GetCountry()<<'\n'
      <<"Name           : "<<Currency.GetCurrencyName()<<'\n'
      <<"Tag            : "<<Currency.GetCurrencyTag()<<'\n'
      <<"Rate           : "<<Currency.GetCurrencyRate()<<'\n'
      <<"__________________________________________________\n"<<endl;
}

void clsFindScreen::Find()
{
  _DrawScreenHeader("\t\tFind Currency");
  clsCurrency Currency;
  
  string Choice = _GetChoice(), Check = "Enter a " + Choice + ": ", Answer = "";
  
  Answer = clsInputValidate::ReadString(Check.c_str());

  while (!clsCurrency::IsCurrencyExist(Answer, Choice)) {
    cout<<"Failed re-";
    Answer = clsInputValidate::ReadString(Check.c_str());
  }

  if (Choice == "Tag" || Choice == "Country") {
    if (Choice == "Tag") Currency = clsCurrency::FindByTag(Answer);
    else Currency = clsCurrency::FindByCountry(Answer);
  } else {
    cout<<"Nothing found!\n";
    return;
  }
  
  _PrintCurrencyRecord(Currency);
}
