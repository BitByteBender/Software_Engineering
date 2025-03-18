#include "../headers/clsDeleteUserScreen.hpp"

void clsDeleteUser::_ReadStr(clsUser &User)
{
  User.SetPassword(clsInputValidate::ReadString("Enter a Password: "));
  User.SetPermissions(clsInputValidate::ReadIntegerNumber("Enter a Permissions: "));
  User.SetFirstname(clsInputValidate::ReadString("Enter a Firstname: "));
  User.SetLastname(clsInputValidate::ReadString("Enter a Lastname: "));
  User.SetEmail(clsInputValidate::ReadString("Enter an Email: "));
  User.SetPhonenum(clsInputValidate::ReadString("Enter a Phone number: "));
}

void clsDeleteUser::_PrintUser(clsUser User)
{
  cout<<"Bank User Record\n"
      <<"----------------------------------------\n"
      <<"Firstname      :  "<<User.GetFirstname()<<'\n'
      <<"Lastname       :  "<<User.GetLastname()<<'\n'
      <<"Fullname       :  "<<User.GetFullname()<<'\n'
      <<"Email          :  "<<User.GetEmail()<<'\n'
      <<"Phone Number   :  "<<User.GetPhonenum()<<'\n'
      <<"Username       :  "<<User.GetUsername()<<'\n'
      <<"Password       :  "<<User.GetPassword()<<'\n'
      <<"Permissions    :  "<<User.GetPermissions()<<'\n'
      <<"----------------------------------------\n"<<endl;
}

void clsDeleteUser::DeleteUser()
{
  clsUser User;
  string Title = "\t     Delete User Screen", Username = "";

  _DrawScreenHeader(Title);
  Username = clsInputValidate::ReadString("Enter a username: ");
  
  while (!clsUser::IsUserExist(Username)) {
    cout<<"Account with the following ["<<Username<<"] does not exists!\n";
    Username = clsInputValidate::ReadString("re-enter a username: ");
  }

  User = clsUser::Find(Username);
  _PrintUser(User);

  cout<<"Are you sure you want to delete this user(Y/n): ";
  char Check = 'n';
  cin>>Check;

  if (Check == 'y' || Check == 'Y') {
    if (User.Delete()) {
      cout<<"User has been deleted successfully\n";
      _PrintUser(User);
    } else cout<<"\nError User was not deleted\n";
  }
}
