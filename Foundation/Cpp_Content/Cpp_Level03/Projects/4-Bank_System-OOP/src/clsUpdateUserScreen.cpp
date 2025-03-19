#include "../headers/clsUpdateUserScreen.hpp"

int16_t clsUpdateUser::_ReadPermissionsToSet()
{
  int16_t Permissions = 0;
  char Answer = 'n';

  cout<<"\nDo you want to give full Permissions? (y/n): ";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') return (-1);

  cout<<"\nDo you want to give access to:\n";
  cout<<"\nShow Client List? (y/n): ";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') Permissions += clsUser::enPermissions::ListClients;

  cout<<"\nAdd new client? (y/n): ";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') Permissions += clsUser::enPermissions::AddNewClient;

  cout<<"\nDelete client? (y/n): ";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') Permissions += clsUser::enPermissions::DeleteClient;

  cout<<"\nUpdate client? (y/n): ";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') Permissions += clsUser::enPermissions::UpdateClient;

  cout<<"\nFind client? (y/n): ";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') Permissions += clsUser::enPermissions::ListClients;

  cout<<"\nTransactions? (y/n): ";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') Permissions += clsUser::enPermissions::Trx;

  cout<<"\nManage Users? (y/n): ";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') Permissions += clsUser::enPermissions::ManageUsers;
  
  return (Permissions);
}

void clsUpdateUser::_ReadStr(clsUser &User)
{
  User.SetFirstname(clsInputValidate::ReadString("Enter a Firstname: "));
  User.SetLastname(clsInputValidate::ReadString("Enter a Lastname: "));
  User.SetEmail(clsInputValidate::ReadString("Enter an Email: "));
  User.SetPhonenum(clsInputValidate::ReadString("Enter a Phone number: "));
  User.SetPassword(clsInputValidate::ReadString("Enter a Password: "));
  User.SetPermissions(_ReadPermissionsToSet());
}

void clsUpdateUser::_PrintUser(clsUser User)
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

void clsUpdateUser::UpdateUser()
{
  clsUser User;
  char Answer = 'n';
  
  string Title = "\t     Update User Screen";
  _DrawScreenHeader(Title);
  
  string Username = clsInputValidate::ReadString("Enter a username to update: ");
  
  while (!clsUser::IsUserExist(Username)) {
      cout<<"username with the following ["<<Username<<"] does not exist!\n";
      Username = clsInputValidate::ReadString("re-enter a username to update: ");
  }
  
  User = clsUser::Find(Username);
  _PrintUser(User);
  
  cout<<"\nDo you want to update this user?\n";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') {
    _ReadStr(User);
    clsUser::enSaveResults SaveResult;
    SaveResult = User.Save();

    switch (SaveResult) {
    case (clsUser::enSaveResults::svFailedEmptyObj):
      cout<<"Failed to save an empty object\n";
      break;
    case (clsUser::enSaveResults::svSucceeded):
      cout<<"Obj has been updated/saved\n";
      _PrintUser(User);
      break;
    }
  } else cout<<"\nUpdate Operation Terminated!\n";
}
