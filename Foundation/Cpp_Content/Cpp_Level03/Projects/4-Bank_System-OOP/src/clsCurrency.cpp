#include "../headers/clsCurrency.hpp"

clsCurrency::clsCurrency() {};

clsCurrency::clsCurrency(enMode Mode, string Country, string Name, string Tag, double Rate)
  : m_Mode(Mode), m_Country(Country), m_Name(Name), m_Tag(Tag), m_Rate(Rate) {};

string clsCurrency::GetCountry() const
{
  return (m_Country);
}

string clsCurrency::GetCurrencyName() const
{
  return (m_Name);
}

string clsCurrency::GetCurrencyTag() const
{
  return (m_Tag);
}

void clsCurrency::SetCurrencyRate(double Rate)
{
  m_Rate = Rate;
}

double clsCurrency::GetCurrencyRate() const
{
  return (m_Rate);
}

bool clsCurrency::IsEmpty() const
{
  return (m_Mode == enMode::EmptyMode);
}

clsCurrency clsCurrency::_ConvertLineToCurrencyObj(string Line)
{
  vector <const char*> vCurr = clsString::GetWords(Line.c_str(), "#//#");

  return (clsCurrency(enMode::UpdateMode, string(vCurr[0]), string(vCurr[2]), string(vCurr[1]), stod(string(vCurr[3]))));
}

clsCurrency clsCurrency::_GetEmptyCurrencyObject()
{
  return (clsCurrency(enMode::EmptyMode, "", "", "", 0.0));
}

clsCurrency clsCurrency::FindByTag(string Tag)
{
  fstream File;
  File.open("Currencies.txt", ios::in);
  Tag = clsString::toUpper(Tag.c_str());

  if (File.is_open()) {
    string Line = "";
    clsCurrency Currency;
    
    while (getline(File, Line)) {
      Currency = _ConvertLineToCurrencyObj(Line);

      if (Tag == Currency.GetCurrencyTag()) {
	File.close();
	return (Currency);
      }
    }
    File.close();
  }

  cout<<"check\n";
  return (_GetEmptyCurrencyObject());
}

clsCurrency clsCurrency::FindByCountry(string Country)
{
  fstream File;
  File.open("Currencies.txt", ios::in);

  if (File.is_open()) {
    string Line = "";
    clsCurrency Currency;
    
    while (getline(File, Line)) {
      Currency = _ConvertLineToCurrencyObj(Line);
      if (clsString::toUpper(Country.c_str()) == Currency.GetCountry())
	File.close();
	return (Currency);
    }
    File.close();
  }

  return (_GetEmptyCurrencyObject());
}

vector <clsCurrency> clsCurrency::GetCurrencyList()
{
  vector <clsCurrency> vCurrList;
  fstream File;
  File.open("Currencies.txt", ios::in);

  if (File.is_open()) {
    string Line = "";
    while (getline(File, Line)) {
      vCurrList.push_back(_ConvertLineToCurrencyObj(Line));
    }
    File.close();
  }
  
  return (vCurrList);
}

bool clsCurrency::IsCurrencyExist(string Choice, string Tag)
{
  clsCurrency Currency;
  
  if (Tag == "Tag") Currency = FindByTag(Choice);
  else Currency = FindByCountry(Choice);
  
  return (!Currency.IsEmpty());  
}

string clsCurrency::_ConvertRecToLine(clsCurrency &Currency)
{
  string Line;

  Line = Currency.m_Country + "#//#" + Currency.m_Tag + "#//#";
  Line += Currency.m_Name + "#//#" + to_string(Currency.m_Rate);
  
  return (Line);
}

void clsCurrency::_SaveRecordToFile(vector <clsCurrency> vCurrency)
{
  fstream File;
  File.open("Currencies.txt", ios::out);

  if (File.is_open()) {
    for (clsCurrency &C:vCurrency) {
      File<<_ConvertRecToLine(C)<<'\n';
    }
    File.close();
  }
}

void clsCurrency::_Update()
{
  vector <clsCurrency> vCurrList = GetCurrencyList();
  
  for (clsCurrency &Rec:vCurrList) {
    if (Rec.GetCurrencyTag() == GetCurrencyTag()) {
      Rec = *this;
      break;
    }
  }

  _SaveRecordToFile(vCurrList);
}

void clsCurrency::Update(double Rate)
{
  m_Rate = Rate;
  _Update();
}

double clsCurrency::CalcRate(double Amount, string TagA, string TagB)
{
  double Rate = 0.0;
  
  if (FindByTag(TagA).GetCurrencyTag() != "USD" && FindByTag(TagB).GetCurrencyTag() != "USD") {
    Rate = Amount / FindByTag(TagA).GetCurrencyRate();
    Rate = Rate * FindByTag(TagB).GetCurrencyRate();
  } else {
    if (FindByTag(TagA).GetCurrencyTag() == "USD")
      Rate = Amount * FindByTag(TagB).GetCurrencyRate();
    else Rate = Amount / FindByTag(TagA).GetCurrencyRate();
  }

  return (Rate);
}
