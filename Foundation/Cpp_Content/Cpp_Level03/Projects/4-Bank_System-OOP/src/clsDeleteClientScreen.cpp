#include "../headers/clsDeleteClientScreen.hpp"

void clsDeleteClientScreen::_ReadStr(clsBankClient &Client)
{
  Client.SetPincode(clsInputValidate::ReadString("Enter a Pincode: "));
  Client.SetBalance(clsInputValidate::ReadDblNumber("Enter a Balance: "));
  Client.SetFirstname(clsInputValidate::ReadString("Enter a Firstname: "));
  Client.SetLastname(clsInputValidate::ReadString("Enter a Lastname: "));
  Client.SetEmail(clsInputValidate::ReadString("Enter an Email: "));
  Client.SetPhonenum(clsInputValidate::ReadString("Enter a Phone number: "));
}

void clsDeleteClientScreen::_PrintClient(clsBankClient Client)
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

void clsDeleteClientScreen::DeleteClient()
{
  clsBankClient Client;
  string Title = "\t     Delete Client Screen", AccNum = "";

  _DrawScreenHeader(Title);
  AccNum = clsInputValidate::ReadString("Enter an account number: ");
  
  while (!clsBankClient::IsClientExist(AccNum)) {
    cout<<"Account number with the following ["<<AccNum<<"] does not exists!\n";
    AccNum = clsInputValidate::ReadString("re-enter an account number: ");
  }

  Client = clsBankClient::Find(AccNum);
  _PrintClient(Client);

  cout<<"Are you sure you want to delete this client(Y/n): ";
  char Check = 'n';
  cin>>Check;

  if (Check == 'y' || Check == 'Y') {
    if (Client.Delete()) {
      cout<<"Client has been deleted successfully\n";
      _PrintClient(Client);
    } else cout<<"\nError Client was not deleted\n";
  }
}
