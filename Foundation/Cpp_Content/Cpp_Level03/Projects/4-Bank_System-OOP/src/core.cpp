#include "../headers/core.hpp"
/*
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
*/
/*
void PrintClientRecordLine(clsBankClient Client)
{
  cout<<"| "<<setw(15)<<left<<Client.GetAccountNumber();
  cout<<"| "<<setw(20)<<left<<Client.GetFullname();
  cout<<"| "<<setw(12)<<left<<Client.GetPhonenum();
  cout<<"| "<<setw(20)<<left<<Client.GetEmail();
  cout<<"| "<<setw(10)<<left<<Client.GetPincode();
  cout<<"| "<<setw(12)<<left<<Client.GetBalance();
}

void ShowClientsList()
{
  vector <clsBankClient> vClients = clsBankClient::GetClientList();
  cout<<"\n"<<clsUtil::Tabs(5)<<"Client List ("<<vClients.size()<<") Client(s).\n";
  cout<<"______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;

  cout<<"| "<<left<<setw(15)<<"Account Number";
  cout<<"| "<<left<<setw(20)<<"Client Name";
  cout<<"| "<<left<<setw(12)<<"Phone";
  cout<<"| "<<left<<setw(20)<<"Email";
  cout<<"| "<<left<<setw(10)<<"Pin Code";
  cout<<"| "<<left<<setw(12)<<"Balance";
  cout<<"\n______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;

  if (vClients.size() == 0)
    cout<<clsUtil::Tabs(3)<<"No Clients Available In the System!";
  else {
    for (const clsBankClient &Rec:vClients) {
      PrintClientRecordLine(Rec);
      cout<<endl;
    }
  }
  cout<<"______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;
}
*/
void PrintClientRecordBalanceLine(clsBankClient Client)
{
  cout<<"| "<<setw(15)<<left<<Client.GetAccountNumber();
  cout<<"| "<<setw(40)<<left<<Client.GetFullname();
  cout<<"| "<<setw(12)<<left<<Client.GetBalance();
}

void ShowClientsTotalBalancesList()
{
  vector <clsBankClient> vClients = clsBankClient::GetClientList();
  double TotalBalance = 0.0;
  
  cout<<"\n"<<clsUtil::Tabs(5)<<"Client List ("<<vClients.size()<<") Client(s).\n";
  cout<<"______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;

  cout<<"| "<<left<<setw(15)<<"Account Number";
  cout<<"| "<<left<<setw(40)<<"Client Name";
  cout<<"| "<<left<<setw(12)<<"Balance";
  cout<<"\n______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;

  TotalBalance = clsBankClient::GetTotalBalances();

  if (vClients.size() == 0)
    cout<<clsUtil::Tabs(4)<<"No Clients Available In the System!";
  else {
    for (const clsBankClient &Rec:vClients) {
      PrintClientRecordBalanceLine(Rec);
      cout<<endl;
    }
  }
  cout<<"______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;
  cout<<clsUtil::Tabs(5)<<" Total Balances = "<<TotalBalance <<endl;
}
