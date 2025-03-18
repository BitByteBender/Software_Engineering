#ifndef CLSBANKCLIENT_HPP
#define CLSBANKCLIENT_HPP

#include "clsperson.hpp"
#include <fstream>
#include <iomanip>

using std::setw;
using std::left;
using std::fstream;
using std::ios;

class clsBankClient : public clsPerson
{
private:
  enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 };
  
  enMode m_Mode = enMode::EmptyMode;
  string m_AccountNumber = "";
  string m_PinCode = "";
  double m_Balance = 0;
  bool m_Marked = false;
  
  static clsBankClient _ConvertLineToClientObject(string Line, string Separator="#//#");
  static clsBankClient _GetEmptyClientObject();
  static string _ConvertClientObjectToLine(clsBankClient ClientObj, string Separator="#//#");
  static vector <clsBankClient> _Loader(string Filename);
  static void _Saver(vector <clsBankClient> &vClientObj);
  void _Update();
  void _AddNew();
  void _AddDataLineToFile(string Line);
public:
  clsBankClient();
  clsBankClient(enMode Mode, string AccNum, string Pincode, double Balance, string Firstname, string Lastname, string Email, string Phonenum);

  string GetAccountNumber(void) const;

  bool IsEmpty() const;
  
  void SetPincode(string Pincode);
  string GetPincode(void) const;

  void SetBalance(double Balance);
  double GetBalance(void) const;

  /*
    Moved to the UI_Layer
    void Print(void);
  */

  static clsBankClient Find(string AccNum);
  static clsBankClient Find(string AccNum, string Pincode);
  static bool IsClientExist(string AccNum);
  
  static clsBankClient GetAddNewClientObject(string AccNum);

  static clsBankClient GetDeletedClientObject(clsBankClient Client);
  bool Delete();

  enum enSaveResults { svFailedEmptyObj = 0, svSucceeded = 1, svFailedAccNumExists = 2 };
  enSaveResults Save();

  static vector <clsBankClient> GetClientList();
  static double GetTotalBalances();

  void Deposit(double Amount);
  bool Withdraw(double Amount);
};
#endif /* CLSBANKCLIENT_HPP */
