#include "../headers/clsUpdateClientScreen.hpp"

void clsUpdateClientScreen::_ReadStr(clsBankClient &Client)
{
  Client.SetPincode(clsInputValidate::ReadString("Enter a Pincode: "));
  Client.SetBalance(clsInputValidate::ReadDblNumber("Enter a Balance: "));
  Client.SetFirstname(clsInputValidate::ReadString("Enter a Firstname: "));
  Client.SetLastname(clsInputValidate::ReadString("Enter a Lastname: "));
  Client.SetEmail(clsInputValidate::ReadString("Enter an Email: "));
  Client.SetPhonenum(clsInputValidate::ReadString("Enter a Phone number: "));
}

void clsUpdateClientScreen::_PrintClient(clsBankClient Client)
{
  cout<<"Bank Client Record\n"
      <<"----------------------------------------\n"
      <<"Firstname      :  "<<Client.GetFirstname()<<'\n'
      <<"Lastname       :  "<<Client.GetLastname()<<'\n'
      <<"Fullname       :  "<<Client.GetFullname()<<'\n'
      <<"Email          :  "<<Client.GetEmail()<<'\n'
      <<"Phone Number   :  "<<Client.GetPhonenum()<<'\n'
      <<"Account Number :  "<<Client.GetAccountNumber()<<'\n'
      <<"Password       :  "<<Client.GetPincode()<<'\n'
      <<"Balance        :  "<<Client.GetBalance()<<'\n'
      <<"----------------------------------------\n"<<endl;
}

void clsUpdateClientScreen::UpdateClient()
{
  clsBankClient Client;
  string Title = "\t     Update Client Screen";
  _DrawScreenHeader(Title);
  
  string AccNum = clsInputValidate::ReadString("Enter an account number to update: ");
  
  while (!clsBankClient::IsClientExist(AccNum)) {
      cout<<"Account number with the following ["<<AccNum<<"] does not exist!\n";
      AccNum = clsInputValidate::ReadString("re-enter an account number to update: ");
  }
  
  Client = clsBankClient::Find(AccNum);
  _PrintClient(Client);
  
  _ReadStr(Client);

  clsBankClient::enSaveResults SaveResult;
  SaveResult = Client.Save();

  switch (SaveResult) {
  case (clsBankClient::enSaveResults::svFailedEmptyObj):
    cout<<"Failed to save an empty object\n";
    break;
  case (clsBankClient::enSaveResults::svSucceeded):
    cout<<"Obj has been updated/saved\n";
    _PrintClient(Client);
    break;
  }
}
