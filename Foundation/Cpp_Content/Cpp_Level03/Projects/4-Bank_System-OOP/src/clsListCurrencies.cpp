#include "../headers/clsListCurrencies.hpp"


void clsListCurrencies::_PrintListCurrencies(clsCurrency &Currency)
{
  cout<<"| "<<clsUtil::SmartSpacer(Currency.GetCountry(), 30)
      <<"| "<<clsUtil::SmartSpacer(Currency.GetCurrencyName(), 30)
      <<"| "<<clsUtil::SmartSpacer(Currency.GetCurrencyTag(), 23)
      <<"| "<<clsUtil::SmartSpacer(to_string(Currency.GetCurrencyRate()), 17)
      <<endl;
}

void clsListCurrencies::ShowListCurrencies()
{
  vector <clsCurrency> vCurrList;
  string Subtitle = "";
  
  vCurrList = clsCurrency::GetCurrencyList();
  Subtitle = "\t\t(" + to_string(vCurrList.size()) + ") Record(s)";
  
  _DrawScreenHeader("\t     Currency List Screen", Subtitle);
  _ShowStats();

  cout<<"___________________________________________________________________________"
      <<"_____________________________________________________________________\n"
      <<"| Country Name    "<<clsUtil::Tabs(2)
      <<"| Currency Name          "<<clsUtil::Tabs(1)
      <<"| Currency Tag    "<<clsUtil::Tabs(1)
      <<"| Rate Per($1)    "<<clsUtil::Tabs(1)
      <<"\n__________________________________________________________________________"
      <<"______________________________________________________________________\n";

  if (vCurrList.size() == 0)
    cout<<"No Currency is found\n";
  else {
    for (clsCurrency &Rec:vCurrList)
      _PrintListCurrencies(Rec);
  }
  
  cout<<"___________________________________________________________________________"
      <<"_____________________________________________________________________\n"<<endl;
}
