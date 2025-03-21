#include "../headers/clsFindClientScreen.hpp"

void clsFindClientScreen::_PrintClient(clsBankClient Client)
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

void clsFindClientScreen::FindClient()
{
  if (!_CheckAccessRights(clsUser::enPermissions::FindClient))
      return ;
  clsBankClient Client;
  string Title = "\t     Find Client Screen";
  _DrawScreenHeader(Title);
  _ShowStats();
  
  string AccNum = clsInputValidate::ReadString("Enter an account number to update: ");
  
  while (!clsBankClient::IsClientExist(AccNum)) {
      cout<<"Account number with the following ["<<AccNum<<"] does not exist!\n";
      AccNum = clsInputValidate::ReadString("re-enter an account number: ");
  }
  
  Client = clsBankClient::Find(AccNum);

  if (!Client.IsEmpty()) cout<<"\nClient Found!\n";
  else cout<<"\nClient has not been found!\n";
  
  _PrintClient(Client);
}
