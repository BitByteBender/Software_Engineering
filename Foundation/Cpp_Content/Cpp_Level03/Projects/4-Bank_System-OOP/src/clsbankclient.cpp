#include "../headers/clsbankclient.hpp"

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

void clsBankClient::Print(void)
{
  cout<<"Bank Client Record\n"
      <<"----------------------------------------\n"
      <<"Firstname      :  "<<clsPerson::GetFirstname()<<'\n'
      <<"Lastname       :  "<<clsPerson::GetLastname()<<'\n'
      <<"Fullname       :  "<<clsPerson::GetFullname()<<'\n'
      <<"Email          :  "<<clsPerson::GetEmail()<<'\n'
      <<"Phone Number   :  "<<clsPerson::GetPhonenum()<<'\n'
      <<"Account Number :  "<<GetAccountNumber()<<'\n'
      <<"Password       :  "<<GetPincode()<<'\n'
      <<"Balance        :  "<<GetBalance()<<'\n'
      <<"----------------------------------------\n"<<endl;
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
