#include "../headers/clsTransferScreen.hpp"

bool clsTransferScreen::_IsAccNum(string AccNum)
{
  if (clsBankClient::IsClientExist(AccNum)) {
    return (true);
  }
  
  return (false);
}

clsBankClient clsTransferScreen::_GetUserByAccNum(const char *Msg)
{
  clsBankClient Client;
  
  string AccNum = clsInputValidate::ReadString(Msg);
  
  while (!_IsAccNum(AccNum)) {
    cout<<"Account not found\n";
    AccNum = clsInputValidate::ReadString(Msg);
  }

  Client = clsBankClient::Find(AccNum);
  
  return (Client);
}

void clsTransferScreen::_PrintUserCardInfo(clsBankClient &Client)
{
  cout<<"Client Card:\n"
      <<"__________________________\n"
      <<"Fullname       : "<<Client.GetFullname()<<'\n'
      <<"Account number : "<<Client.GetAccountNumber()<<'\n'
      <<"Balance        : "<<Client.GetBalance()<<'\n'
      <<"__________________________\n"<<endl;
}

double clsTransferScreen::_ReadAmount(clsBankClient &Client)
{
  double Balance = clsInputValidate::ReadDblNumber("Enter transfer amount: ");

  while (Client.GetBalance() < Balance) {
    cout<<"\nAmount Exceeds the available Balance, ";
    Balance = clsInputValidate::ReadDblNumber("Enter another transfer amount: ");
  }

  return (Balance);
}

void clsTransferScreen::Transfer()
{
  clsBankClient ClientSrc, ClientDst;

  _DrawScreenHeader("\t\tTransfer Screen");
  _ShowStats();
  
  ClientSrc = _GetUserByAccNum("Please enter an account number to transfer from: ");
  _PrintUserCardInfo(ClientSrc);

  ClientDst = _GetUserByAccNum("Please enter an account number to transfer to: ");
  _PrintUserCardInfo(ClientDst);

  double Balance = _ReadAmount(ClientSrc);

  cout<<"Are you sure you want to perform this operation? (Y/N): ";
  char Answer = 'n';
  cin>>Answer;

  if (Answer == 'y' || Answer == 'Y') {
    if (ClientSrc.Transfer(Balance, ClientDst))
      cout<<"Operation done!\n";
  } else cout<<"Operation Terminated\n";

  _PrintUserCardInfo(ClientSrc);
  _PrintUserCardInfo(ClientDst);
}
