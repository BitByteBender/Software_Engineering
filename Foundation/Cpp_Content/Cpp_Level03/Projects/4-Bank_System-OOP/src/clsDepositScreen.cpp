#include "../headers/clsDepositScreen.hpp"

string clsDepositScreen::_ReadAccNum(const char *Msg)
{
  return (clsInputValidate::ReadString(Msg));
}

void clsDepositScreen::_PrintClient(clsBankClient Client)
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

void clsDepositScreen::PerformDeposit()
{
  clsBankClient Client;
  string AccNum = "";
  _DrawScreenHeader("\t\tDeposit Screen");

  AccNum = _ReadAccNum("Enter an account number: ");

  while (!clsBankClient::IsClientExist(AccNum)) {
    cout<<"The account number entered does not exist\n";
    AccNum = _ReadAccNum("Please re-enter an account number: ");
  }

  Client = clsBankClient::Find(AccNum);
  _PrintClient(Client);

  char Check = clsInputValidate::ReadString("Do you want to perform the deposit Operation (Y/N) ")[0];
					   
  if (Check == 'y' || Check == 'Y') {
    double Amount = clsInputValidate::ReadDblNumber("Enter a new balance: ");
    Client.Deposit(Amount);
    cout<<"New balance is: "<<Client.GetBalance()<<endl;
  } else cout<<"Deposit Operation is Terminated!\n";
}
