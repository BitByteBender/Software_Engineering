#include "../headers/clsAddNewUsers.hpp"

int16_t clsAddNewUser::_ReadPermissionsToSet()
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

  cout<<"\nShow LogFile? (y/n): ";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') Permissions += clsUser::enPermissions::LogFile;

  cout<<"\nShow Currency Exchange? (y/n): ";
  cin>>Answer;
  if (Answer == 'y' || Answer == 'Y') Permissions += clsUser::enPermissions::CurrencyExchange;
  
  return (Permissions);
}

void clsAddNewUser::_ReadStr(clsUser &User)
{
  User.SetFirstname(clsInputValidate::ReadString("Enter a Firstname: "));
  User.SetLastname(clsInputValidate::ReadString("Enter a Lastname: "));
  User.SetEmail(clsInputValidate::ReadString("Enter an Email: "));
  User.SetPhonenum(clsInputValidate::ReadString("Enter a Phone number: "));
  User.SetPassword(clsInputValidate::ReadString("Enter a Password: "));
  User.SetPermissions(_ReadPermissionsToSet());
}

void clsAddNewUser::_PrintUser(clsUser User)
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

void clsAddNewUser::AddNewUser()
{
  clsUser User;
  string Title = "\t     Add New User Screen";
  _DrawScreenHeader(Title);
  
  string Username = clsInputValidate::ReadString("Enter a username: ");
  
  while (clsUser::IsUserExist(Username)) {
      cout<<"User with the following ["<<Username<<"] does exist!\n";
      Username = clsInputValidate::ReadString("re-enter a username: ");
  }
  
  User = clsUser::GetAddNewUserObject(Username);
  _ReadStr(User);

  clsUser::enSaveResults SaveResult;
  SaveResult = User.Save();

  switch (SaveResult) {
  case (clsUser::enSaveResults::svFailedEmptyObj):
    cout<<"Error user was not saved due to an empty/null data!\n";
    break;
  case (clsUser::enSaveResults::svSucceeded):
    cout<<"User has been added successfully!\n";
    _PrintUser(User);
    break;
  case (clsUser::enSaveResults::svFailedUsernameExists):
    cout<<"Error user was not saved properlly, Username already exists!\n";
    break;
  }
}
