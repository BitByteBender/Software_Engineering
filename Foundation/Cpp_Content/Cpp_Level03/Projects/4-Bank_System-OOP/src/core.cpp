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

void AddNewClient()
{
  clsBankClient Client;
  string AccNum = clsInputValidate::ReadString("Enter an account number: ");
  
  while (clsBankClient::IsClientExist(AccNum)) {
      cout<<"Account number with the following ["<<AccNum<<"] does exist!\n";
      AccNum = clsInputValidate::ReadString("re-enter an account number: ");
  }
  
  Client = clsBankClient::GetAddNewClientObject(AccNum);
  ReadStr(Client);

  clsBankClient::enSaveResults SaveResult;
  SaveResult = Client.Save();

  switch (SaveResult) {
  case (clsBankClient::enSaveResults::svFailedEmptyObj):
    cout<<"Error account was not saved due to an empty/null data!\n";
    break;
  case (clsBankClient::enSaveResults::svSucceeded):
    cout<<"Account has been added successfully!\n";
    Client.Print();
    break;
  case (clsBankClient::enSaveResults::svFailedAccNumExists):
    cout<<"Error account was not saved properlly, Account Num already exists!\n";
    break;
  }
}

void DeleteClient()
{
  clsBankClient Client;
  
  string AccNum = "";
  AccNum = clsInputValidate::ReadString("Enter an account number: ");
  
  while (!clsBankClient::IsClientExist(AccNum)) {
    cout<<"Account number with the following ["<<AccNum<<"] does not exists!\n";
    AccNum = clsInputValidate::ReadString("re-enter an account number: ");
  }

  Client = clsBankClient::Find(AccNum);
  Client.Print();

  cout<<"Are you sure you want to delete this client(Y/n): ";
  char Check = 'n';
  cin>>Check;

  if (Check == 'y' || Check == 'Y') {
    if (Client.Delete()) {
      cout<<"Client has been deleted successfully\n";
      Client.Print();
    } else cout<<"\nError Client was not deleted\n";
  }
}
