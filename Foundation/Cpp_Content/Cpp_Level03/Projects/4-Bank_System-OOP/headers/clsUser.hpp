#ifndef CLSUSER_HPP
#define CLSUSER_HPP

#include "clsperson.hpp"
#include <fstream>
#include <iomanip>

using std::setw;
using std::left;
using std::fstream;
using std::ios;

class clsUser : public clsPerson
{
private:
  enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 };
  
  enMode m_Mode = enMode::EmptyMode;
  string m_Username = "";
  string m_Password = "";
  int16_t m_Permissions = 0;
  bool m_Marked = false;
  
  static clsUser _ConvertLineToUserObject(string Line, string Separator="#//#");
  static clsUser _GetEmptyUserObject();
  static string _ConvertUserObjectToLine(clsUser UserObj, string Separator="#//#");
  static vector <clsUser> _Loader(string Filename);
  static void _Saver(vector <clsUser> &vUserObj);
  void _Update();
  void _AddNew();
  void _AddDataLineToFile(string Line);
public:
  enum enPermissions
  {
    All = -1,
    ListClients = 1,
    AddNewClient = 2,
    DeleteClient = 4,
    UpdateClient = 8,
    FindClient = 16,
    Trx = 32,
    ManageUsers = 64,
  };
  
  clsUser();
  clsUser(enMode Mode, string Firstname, string Lastname, string Email, string Phonenum, string Username, string Password, int16_t Permissions);

  void SetUsername(string Username);
  string GetUsername(void) const;

  bool IsEmpty() const;
  
  void SetPassword(string Password);
  string GetPassword(void) const;

  void SetPermissions(int16_t Permissions);
  int16_t GetPermissions(void) const;

  static clsUser Find(string Username);
  static clsUser Find(string Username, string Password);
  static bool IsUserExist(string Username);
  
  static clsUser GetAddNewUserObject(string Username);

  static clsUser GetDeletedUserObject(clsUser User);
  bool Delete();

  enum enSaveResults { svFailedEmptyObj = 0, svSucceeded = 1, svFailedUsernameExists = 2 };
  enSaveResults Save();

  static vector <clsUser> GetUserList();
};
#endif /* CLSUSER_HPP */
