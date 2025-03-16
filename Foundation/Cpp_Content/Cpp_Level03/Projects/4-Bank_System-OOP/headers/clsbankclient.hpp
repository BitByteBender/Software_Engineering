#ifndef CLSBANKCLIENT_HPP
#define CLSBANKCLIENT_HPP

#include "clsperson.hpp"
#include <fstream>

using std::fstream;
using std::ios;

class clsBankClient : public clsPerson
{
private:
  enum enMode { EmptyMode = 0, UpdateMode = 1 };
  
  enMode m_Mode = enMode::EmptyMode;
  string m_AccountNumber = "";
  string m_PinCode = "";
  double m_Balance = 0;

  static clsBankClient _ConvertLineToClientObject(string Line, string Separator="#//#");
  static clsBankClient _GetEmptyClientObject();
  static string _ConvertClientObjectToLine(clsBankClient ClientObj, string Separator="#//#");
  static vector <clsBankClient> _Loader(string Filename);
  static void _Saver(vector <clsBankClient> &vClientObj);
  void _Update();
public:
  clsBankClient();
  clsBankClient(enMode Mode, string AccNum, string Pincode, double Balance, string Firstname, string Lastname, string Email, string Phonenum);

  /*
    Read only for now (because i'm only using the find method)
    Prolly i will do an incrementor or randomizer
    instead of a Set_method once i get to the Add_method
  */
  string GetAccountNumber(void) const;

  bool IsEmpty() const;
  
  void SetPincode(string Pincode);
  string GetPincode(void) const;

  void SetBalance(double Balance);
  double GetBalance(void) const;

  void Print(void);

  static clsBankClient Find(string AccNum);
  static clsBankClient Find(string AccNum, string Pincode);
  static bool IsClientExist(string AccNum);

  enum enSaveResults { svFailedEmptyObj = 0, svSucceeded = 1};
  enSaveResults Save();
};
#endif /* CLSBANKCLIENT_HPP */
