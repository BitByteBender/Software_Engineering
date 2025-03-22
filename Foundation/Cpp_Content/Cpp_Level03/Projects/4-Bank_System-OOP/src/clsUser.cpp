#include "../headers/clsUser.hpp"

clsUser::clsUser() : clsPerson("", "", "", "") {};
clsUser::clsUser(enMode Mode, string Firstname, string Lastname, string Email, string Phonenum, string Username, string Password, int16_t Permissions)
  : clsPerson(Firstname, Lastname, Email, Phonenum), m_Mode(Mode),
    m_Username(Username), m_Password(Password), m_Permissions(Permissions) {}

void clsUser::SetUsername(string Username)
{
  m_Username = Username;
}

string clsUser::GetUsername() const
{
  return (m_Username);
}

void clsUser::SetPassword(string Password)
{
  m_Password = Password;
}

string clsUser::GetPassword(void) const
{
  return (m_Password);
}

void clsUser::SetPermissions(int16_t Permissions)
{
  m_Permissions = Permissions;
}

int16_t clsUser::GetPermissions(void) const
{
  return (m_Permissions);
}

bool clsUser::IsEmpty() const
{
  return (m_Mode == enMode::EmptyMode);
}

clsUser clsUser::_ConvertLineToUserObject(string Line, string Separator)
{
  vector <const char *> vLine = clsString::GetWords(Line.c_str(), Separator.c_str());
  
  return (clsUser(enMode::UpdateMode, string(vLine[0]), string(vLine[1]), string(vLine[2]), string(vLine[3]),string(vLine[4]), string(vLine[5]), stoi(vLine[6])));
}

clsUser clsUser::_GetEmptyUserObject()
{
  return (clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0));
}

clsUser clsUser::Find(string Username)
{
  fstream File;

  File.open("Users.txt", ios::in);

  if (File.is_open()) {
    string Line = "";
    
    while (getline(File, Line)) {
      if (Line != "") {
	clsUser User = _ConvertLineToUserObject(Line);

	if (User.GetUsername() == Username) {
	  File.close();
	  return (User);
	}
      }
    }
    File.close();
  }

  return (_GetEmptyUserObject());
}

clsUser clsUser::Find(string Username, string Password)
{
  fstream File;

  File.open("Users.txt", ios::in);

  if (File.is_open()) {
    string Line = "";
    
    while (getline(File, Line)) {
      clsUser User = _ConvertLineToUserObject(Line);

      if (User.GetUsername() == Username && User.GetPassword() == Password) {
	File.close();
	return (User);
      }
    }
    File.close();
  }

  return (_GetEmptyUserObject());
}

bool clsUser::IsUserExist(string Username)
{
  clsUser User = clsUser::Find(Username);
  return (!User.IsEmpty());
}

string clsUser::_ConvertUserObjectToLine(clsUser UserObj, string Separator)
{
  string Line = "";

  Line = UserObj.GetFirstname() + Separator;
  Line += UserObj.GetLastname() + Separator;
  Line += UserObj.GetEmail() + Separator;
  Line += UserObj.GetPhonenum() + Separator;
  Line += UserObj.GetUsername() + Separator;
  Line += UserObj.GetPassword() + Separator + to_string(UserObj.GetPermissions());
    
  return (Line);
}

vector <clsUser> clsUser::_Loader(string Filename)
{
  vector <clsUser> vUsers;
  
  fstream File;
  File.open(Filename, ios::in);

  if (File.is_open()) {
    string Line = "";
    while (getline(File, Line)) {
      if (Line != "") vUsers.push_back(_ConvertLineToUserObject(Line));
    }
    File.close();
  }
  
  return (vUsers);
}

void clsUser::_Saver(vector <clsUser> &vUserObj)
{
  fstream File; 
  File.open("Users.txt", ios::out);

  if (File.is_open()) {
    string Rec = "";
    
    for (const clsUser &Obj:vUserObj) {
      if (Obj.m_Marked == false) {
	Rec = _ConvertUserObjectToLine(Obj);
	File << Rec<<'\n';
      }
    }
    File.close();
  }
}

void clsUser::_Update()
{
  vector <clsUser> vUsersObj = _Loader("Users.txt");
  
  for (clsUser &Obj:vUsersObj) {
    if (Obj.GetUsername() == GetUsername()) {
      Obj = *this;
      break;
    }
  }
  
  _Saver(vUsersObj);
  cout<<"End of saving\n"<<endl;
}

clsUser clsUser::GetAddNewUserObject(string Username)
{
  return (clsUser(enMode::AddNewMode, "", "", "", "", Username, "", 0));
}

void clsUser::_AddDataLineToFile(string Line)
{
  fstream File;
  File.open("Users.txt", ios::out | ios::app);

  if (File.is_open()) {
    if (!Line.empty())
      File<<Line<<'\n';

    File.close();
  }
}

void clsUser::_AddNew()
{
  return (_AddDataLineToFile(_ConvertUserObjectToLine(*this)));
}

bool clsUser::Delete()
{
  vector <clsUser> vUsers = _Loader("Users.txt");
  
  for (clsUser &Obj:vUsers) {
    if (Obj.GetUsername() == GetUsername()) {
      Obj.m_Marked = true;
      break;
    }
  }

  _Saver(vUsers);
  cout<<"End of Deletion\n"<<endl;
  *this = _GetEmptyUserObject();
  
  return (true);
}

clsUser::enSaveResults clsUser::Save()
{
  switch (m_Mode) {
  case (enMode::EmptyMode):
    if (IsEmpty())
      return (enSaveResults::svFailedEmptyObj);
    else break;
  case (enMode::UpdateMode):
    _Update();
    break;
  case (enMode::AddNewMode):
    if (IsUserExist(GetUsername())) {
      return (enSaveResults::svFailedUsernameExists);
    } else {
      _AddNew();
      m_Mode = enMode::UpdateMode;
      return (enSaveResults::svSucceeded);
    }
  }
  
  return (enSaveResults::svSucceeded);
}

vector <clsUser> clsUser::GetUserList()
{
  return (_Loader("Users.txt"));
}

bool clsUser::CheckAccessPermission(enPermissions Permission)
{
  if (this->m_Permissions == enPermissions::All) return (true);

  if ((Permission & this->m_Permissions) == Permission)
    return (true);
  else
    return (false);
}

string clsUser::_PreparedData(string Separator)
{
  string Line = "";

  Line += clsDate::GetClockTime() + Separator;
  Line +=  m_Username + Separator;
  Line += m_Password + Separator + to_string(m_Permissions);
  
  return (Line);
}

void clsUser::SaveCurrentUserData()
{
  fstream File;
  File.open("Logfile.txt", ios::out | ios::app);

  if (File.is_open()) {
    string Line = _PreparedData();
    
    if (Line != "")
      File<<Line<<'\n';

    File.close();
  }
}

clsUser::stUserLog clsUser::ConvertLineToRecord(string Line)
{
  vector <const char *> vLine = clsString::GetWords(Line.c_str(), "#//#");
  stUserLog UL;
  
  UL.DateTime = vLine[0];
  UL.Username = vLine[1];
  UL.Passwd = vLine[2];
  UL.Permission = stoi(vLine[3]);

  return (UL);
}

vector <clsUser::stUserLog> clsUser::LoadLogFile()
{
  fstream File;
  File.open("Logfile.txt", ios::in);
  vector <stUserLog> vLogs;
  
  if (File.is_open()) {
    string Line = "";
    
    while (getline(File, Line)) {
      if (Line != "") {
	vLogs.push_back(ConvertLineToRecord(Line));
      }
    }
    File.close();
  }

  return (vLogs);
}
