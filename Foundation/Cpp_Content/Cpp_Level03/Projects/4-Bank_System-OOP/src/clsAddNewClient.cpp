#include "../headers/clsAddNewClient.hpp"

void clsAddNewClient::_ReadStr(clsBankClient &Client)
{
  Client.SetPincode(clsInputValidate::ReadString("Enter a Pincode: "));
  Client.SetBalance(clsInputValidate::ReadDblNumber("Enter a Balance: "));
  Client.SetFirstname(clsInputValidate::ReadString("Enter a Firstname: "));
  Client.SetLastname(clsInputValidate::ReadString("Enter a Lastname: "));
  Client.SetEmail(clsInputValidate::ReadString("Enter an Email: "));
  Client.SetPhonenum(clsInputValidate::ReadString("Enter a Phone number: "));
}

void clsAddNewClient::_PrintClient(clsBankClient Client)
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

void clsAddNewClient::AddNewClient()
{
  if (!_CheckAccessRights(clsUser::enPermissions::AddNewClient))
      return ;
  clsBankClient Client;
  string Title = "\t     Add New Client Screen";
  _DrawScreenHeader(Title);
  _ShowStats();
  
  string AccNum = clsInputValidate::ReadString("Enter an account number: ");
  
  while (clsBankClient::IsClientExist(AccNum)) {
      cout<<"Account number with the following ["<<AccNum<<"] does exist!\n";
      AccNum = clsInputValidate::ReadString("re-enter an account number: ");
  }
  
  Client = clsBankClient::GetAddNewClientObject(AccNum);
  _ReadStr(Client);

  clsBankClient::enSaveResults SaveResult;
  SaveResult = Client.Save();

  switch (SaveResult) {
  case (clsBankClient::enSaveResults::svFailedEmptyObj):
    cout<<"Error account was not saved due to an empty/null data!\n";
    break;
  case (clsBankClient::enSaveResults::svSucceeded):
    cout<<"Account has been added successfully!\n";
    _PrintClient(Client);
    break;
  case (clsBankClient::enSaveResults::svFailedAccNumExists):
    cout<<"Error account was not saved properlly, Account Num already exists!\n";
    break;
  }
}
