#include "../headers/clsWithdrawScreen.hpp"

string clsWithdrawScreen::_ReadAccNum(const char *Msg)
{
  return (clsInputValidate::ReadString(Msg));
}

void clsWithdrawScreen::_PrintClient(clsBankClient Client)
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

void clsWithdrawScreen::PerformWithdraw()
{
  clsBankClient Client;
  string AccNum = "";
  _DrawScreenHeader("\t\tWithdraw Screen");

  AccNum = _ReadAccNum("Enter an account number: ");

  while (!clsBankClient::IsClientExist(AccNum)) {
    cout<<"The account number entered does not exist\n";
    AccNum = _ReadAccNum("Please re-enter an account number: ");
  }

  Client = clsBankClient::Find(AccNum);
  _PrintClient(Client);
  double Amount = clsInputValidate::ReadDblNumber("Enter a new balance: ");

  char Check;
  
  if (Client.GetBalance() >= Amount)
    Check = clsInputValidate::ReadString("Do you want to perform the withdraw Operation (Y/N) ")[0];
					   
  if (Check == 'y' || Check == 'Y') {
    Client.Withdraw(Amount);
    cout<<"New balance is: "<<Client.GetBalance()<<endl;
  } else cout<<"Withdraw Operation is Terminated!\n";
}
