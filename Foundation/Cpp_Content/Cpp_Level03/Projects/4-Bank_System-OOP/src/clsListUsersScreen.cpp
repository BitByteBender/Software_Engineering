#include "../headers/clsListUsersScreen.hpp"

void clsListUsersScreen::_PrintUserRecordLine(clsUser User)
{
  cout<<"| "<<setw(15)<<left<<User.GetUsername();
  cout<<"| "<<setw(20)<<left<<User.GetFullname();
  cout<<"| "<<setw(12)<<left<<User.GetPhonenum();
  cout<<"| "<<setw(20)<<left<<User.GetEmail();
  cout<<"| "<<setw(10)<<left<<User.GetPassword();
  cout<<"| "<<setw(12)<<left<<User.GetPermissions();
}

void clsListUsersScreen::ShowUsersList()
{
vector <clsUser> vUsrs = clsUser::GetUserList();
  string Title = "\t     User List Screen", Subtitle = "\t\t(" + to_string(vUsrs.size()) + ") User(s).";

  _DrawScreenHeader(Title, Subtitle);

  cout<<"\n______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;

  cout<<"| "<<left<<setw(15)<<"Username";
  cout<<"| "<<left<<setw(20)<<"Fullname";
  cout<<"| "<<left<<setw(12)<<"Phone";
  cout<<"| "<<left<<setw(20)<<"Email";
  cout<<"| "<<left<<setw(10)<<"Password";
  cout<<"| "<<left<<setw(12)<<"Permissions";
  cout<<"\n______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;

  if (vUsrs.size() == 0)
    cout<<clsUtil::Tabs(3)<<"No Usrs Available In the System!";
  else {
    for (const clsUser &Rec:vUsrs) {
      _PrintUserRecordLine(Rec);
      cout<<endl;
    }
  }
  cout<<"______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;  
}
