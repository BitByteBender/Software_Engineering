#include "../headers/core.hpp"

void ReadStr(clsBankClient &Client)
{
  Client.SetPincode(clsInputValidate::ReadString("Enter a Pincode: "));
  Client.SetBalance(clsInputValidate::ReadDblNumber("Enter a Balance: "));
  Client.SetFirstname(clsInputValidate::ReadString("Enter a Firstname: "));
  Client.SetLastname(clsInputValidate::ReadString("Enter a Lastname: "));
  Client.SetEmail(clsInputValidate::ReadString("Enter an Email: "));
  Client.SetPhonenum(clsInputValidate::ReadString("Enter a Phone number: "));
}

void UpdateClient()
{
  clsBankClient Client;
  string AccNum = clsInputValidate::ReadString("Enter an account number to update: ");
  
  while (!clsBankClient::IsClientExist(AccNum)) {
      cout<<"Account number with the following ["<<AccNum<<"] does not exist!\n";
      AccNum = clsInputValidate::ReadString("re-enter an account number to update: ");
  }
  
  Client = clsBankClient::Find(AccNum);
  Client.Print();
  
  ReadStr(Client);

  clsBankClient::enSaveResults SaveResult;
  SaveResult = Client.Save();

  switch (SaveResult) {
  case (clsBankClient::enSaveResults::svFailedEmptyObj):
    cout<<"Failed to save an empty object\n";
    break;
  case (clsBankClient::enSaveResults::svSucceeded):
    cout<<"New obj has been saved\n";
    break;
  }
}
