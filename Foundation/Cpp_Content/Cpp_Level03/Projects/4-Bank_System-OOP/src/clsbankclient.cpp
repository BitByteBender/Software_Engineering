#include "../headers/clsbankclient.hpp"

clsBankClient::clsBankClient() : clsPerson("", "", "", "") {};
clsBankClient::clsBankClient(enMode Mode, string AccNum, string Pincode, double Balance,
			     string Firstname, string Lastname, string Email, string Phonenum)
  : clsPerson(Firstname, Lastname, Email, Phonenum), m_Mode(Mode),
    m_AccountNumber(AccNum), m_PinCode(Pincode), m_Balance(Balance) {}

string clsBankClient::GetAccountNumber() const
{
  return (m_AccountNumber);
}

void clsBankClient::SetPincode(string Pincode)
{
  m_PinCode = Pincode;
}

string clsBankClient::GetPincode(void) const
{
  return (m_PinCode);
}

void clsBankClient::SetBalance(double Balance)
{
  m_Balance = Balance;
}

double clsBankClient::GetBalance(void) const
{
  return (m_Balance);
}

bool clsBankClient::IsEmpty() const
{
  return (m_Mode == enMode::EmptyMode);
}

clsBankClient clsBankClient::_ConvertLineToClientObject(string Line, string Separator)
{
  vector <const char *> vLine = clsString::GetWords(Line.c_str(), Separator.c_str());
  
  return (clsBankClient(enMode::UpdateMode, string(vLine[4]),
			string(vLine[5]), stod(string(vLine[6])), string(vLine[0]),
			string(vLine[1]), string(vLine[2]), string(vLine[3])));
}

clsBankClient clsBankClient::_GetEmptyClientObject()
{
  return (clsBankClient(enMode::EmptyMode, "", "", 0, "", "", "", ""));
}

clsBankClient clsBankClient::Find(string AccNum)
{
  fstream File;

  File.open("Clients.txt", ios::in);

  if (File.is_open()) {
    string Line = "";
    
    while (getline(File, Line)) {
      if (Line != "") {
	clsBankClient Client = _ConvertLineToClientObject(Line);

	if (Client.GetAccountNumber() == AccNum) {
	  File.close();
	  return (Client);
	}
      }
    }
    File.close();
  }

  return (_GetEmptyClientObject());
}

clsBankClient clsBankClient::Find(string AccNum, string Pincode)
{
  fstream File;

  File.open("Clients.txt", ios::in);

  if (File.is_open()) {
    string Line = "";
    
    while (getline(File, Line)) {
      clsBankClient Client = _ConvertLineToClientObject(Line);

      if (Client.GetAccountNumber() == AccNum && Client.GetPincode() == Pincode) {
	File.close();
	return (Client);
      }
    }
    File.close();
  }

  return (_GetEmptyClientObject());
}

bool clsBankClient::IsClientExist(string AccNum)
{
  clsBankClient Client = clsBankClient::Find(AccNum);
  return (!Client.IsEmpty());
}

string clsBankClient::_ConvertClientObjectToLine(clsBankClient ClientObj, string Separator)
{
  string Line = "";

  Line = ClientObj.GetFirstname() + Separator;
  Line += ClientObj.GetLastname() + Separator;
  Line += ClientObj.GetEmail() + Separator;
  Line += ClientObj.GetPhonenum() + Separator;
  Line += ClientObj.GetAccountNumber() + Separator;
  Line += ClientObj.GetPincode() + Separator + to_string(ClientObj.GetBalance());
    
  return (Line);
}

vector <clsBankClient> clsBankClient::_Loader(string Filename)
{
  vector <clsBankClient> vClients;
  
  fstream File;
  File.open(Filename, ios::in);

  if (File.is_open()) {
    string Line = "";
    while (getline(File, Line)) {
      if (Line != "") vClients.push_back(_ConvertLineToClientObject(Line));
    }
    File.close();
  }
  
  return (vClients);
}

void clsBankClient::_Saver(vector <clsBankClient> &vClientObj)
{
  fstream File; 
  File.open("Clients.txt", ios::out);

  if (File.is_open()) {
    string Rec = "";
    
    for (const clsBankClient &Obj:vClientObj) {
      if (Obj.m_Marked == false) {
	Rec = _ConvertClientObjectToLine(Obj);
	File << Rec<<'\n';
      }
    }
    File.close();
  }
}

void clsBankClient::_Update()
{
  vector <clsBankClient> vClientsObj = _Loader("Clients.txt");
  
  for (clsBankClient &Obj:vClientsObj) {
    if (Obj.GetAccountNumber() == GetAccountNumber()) {
      Obj = *this;
      break;
    }
  }
  
  _Saver(vClientsObj);
  cout<<"End of saving\n"<<endl;
}

clsBankClient clsBankClient::GetAddNewClientObject(string AccNum)
{
  return (clsBankClient(enMode::AddNewMode, AccNum, "", 0, "", "", "", ""));
}

void clsBankClient::_AddDataLineToFile(string Line)
{
  fstream File;
  File.open("Clients.txt", ios::out | ios::app);

  if (File.is_open()) {
    if (!Line.empty())
      File<<Line<<'\n';

    File.close();
  }
}

void clsBankClient::_AddNew()
{
  return (_AddDataLineToFile(_ConvertClientObjectToLine(*this)));
}
/*
clsBankClient clsBankClient::GetDeletedClientObject(clsBankClient Client)
{
  return (clsBankClient(enMode::DeleteMode, Client.GetAccountNumber(), Client.GetPincode(),
			Client.GetBalance(), Client.GetFirstname(), Client.GetLastname(),
			Client.GetEmail(), Client.GetPhonenum()));
}
*/
bool clsBankClient::Delete()
{
  vector <clsBankClient> vClients = _Loader("Clients.txt");
  
  for (clsBankClient &Obj:vClients) {
    if (Obj.GetAccountNumber() == GetAccountNumber()) {
      Obj.m_Marked = true;
      break;
    }
  }

  _Saver(vClients);
  cout<<"End of Deletion\n"<<endl;
  *this = _GetEmptyClientObject();
  
  return (true);
}

clsBankClient::enSaveResults clsBankClient::Save()
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
    if (IsClientExist(GetAccountNumber())) {
      return (enSaveResults::svFailedAccNumExists);
    } else {
      _AddNew();
      m_Mode = enMode::UpdateMode;
      return (enSaveResults::svSucceeded);
    }
  }
  
  return (enSaveResults::svSucceeded);
}

vector <clsBankClient> clsBankClient::GetClientList()
{
  return (_Loader("Clients.txt"));
}

double clsBankClient::GetTotalBalances()
{
  vector <clsBankClient> vClients = _Loader("Clients.txt");
  double TotalBalance = 0.0;

  for (const clsBankClient &Obj:vClients) {
    TotalBalance += Obj.GetBalance();
  }

  return (TotalBalance);
}

void clsBankClient::Deposit(double Amount)
{
  m_Balance += Amount;
  Save();
}

bool clsBankClient::Withdraw(double Amount)
{
  if (Amount > m_Balance) {
    return (false);
  } else {
    m_Balance -= Amount;
    Save();
    return (true);
  }
}
