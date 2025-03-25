#ifndef CLSCURRENCY_HPP
#define CLSCURRENCY_HPP

#include "clsUser.hpp"

class clsCurrency
{
private:
  enum enMode{EmptyMode = 0, UpdateMode = 1};
  enMode m_Mode = enMode::EmptyMode;
  
  string m_Country = "";
  string m_Name = "";
  string m_Tag = "";
  double m_Rate = 0.0;

  static clsCurrency _GetEmptyCurrencyObject();
  static clsCurrency _ConvertLineToCurrencyObj(string Line);
  static string _ConvertRecToLine(clsCurrency &Currency);
  void _Update();
  void _SaveRecordToFile(vector <clsCurrency> vCurrency);
public:
  clsCurrency();
  clsCurrency(enMode Mode, string Country, string Name, string Tag, double Rate);

  string GetCountry() const;
  string GetCurrencyName() const;
  string GetCurrencyTag() const;

  void SetCurrencyRate(double Rate);
  double GetCurrencyRate() const;

  bool IsEmpty() const;

  static clsCurrency FindByTag(string Tag);
  static clsCurrency FindByCountry(string Country);

  static bool IsCurrencyExist(string Choice, string Tag="Tag");
  static vector <clsCurrency> GetCurrencyList();

  void Update(double Rate);

  static double CalcRate(double Amount, string TagA, string TagB="USD");
};

#endif /* CLSCURRENCY_HPP */
