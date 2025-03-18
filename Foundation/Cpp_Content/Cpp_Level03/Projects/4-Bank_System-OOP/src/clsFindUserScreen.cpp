#include "../headers/clsFindUserScreen.hpp"

void clsFindUser::_PrintUser(clsUser User)
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

void clsFindUser::FindUser()
{
  clsUser User;
  string Title = "\t     Find User Screen";
  _DrawScreenHeader(Title);
  string Username = clsInputValidate::ReadString("Enter an username to update: ");
  
  while (!clsUser::IsUserExist(Username)) {
      cout<<"username with the following ["<<Username<<"] does not exist!\n";
      Username = clsInputValidate::ReadString("re-enter an username: ");
  }
  
  User = clsUser::Find(Username);

  if (!User.IsEmpty()) cout<<"\nUser Found!\n";
  else cout<<"\nUser has not been found!\n";
  
  _PrintUser(User);
}
