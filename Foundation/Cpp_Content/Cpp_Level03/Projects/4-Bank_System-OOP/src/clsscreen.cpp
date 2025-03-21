#include "../headers/clsscreen.hpp"
#include "../headers/global.hpp"
#include "../headers/clsdate.hpp"

void clsScreen::_DrawScreenHeader(string Title, string Subtitle)
{
  cout<<clsUtil::Tabs(5)<<"______________________________________\n\n";
  cout<<clsUtil::Tabs(5)<<"   "<<Title;

  if (Subtitle != "")
    cout<<'\n'<<clsUtil::Tabs(5)<<"   "<<Subtitle;
  cout<<'\n'<<clsUtil::Tabs(5)<<"______________________________________\n\n";
}

bool clsScreen::_CheckAccessRights(clsUser::enPermissions Permission)
{
  if (!CurrentUser.CheckAccessPermission(Permission)) {
    cout<<clsUtil::Tabs(5)<<"_______________________________________";
    cout<<"\n\n"<<clsUtil::Tabs(5)<<"  Access Denied! Contact your Admin.";
    cout<<"\n"<<clsUtil::Tabs(5)<<"_______________________________________\n\n";
    return (false);
  } else return (true);
}

void clsScreen::_ShowStats()
{
  cout<<clsUtil::Tabs(5)<<"User: "<<CurrentUser.GetUsername()<<'\n';
  cout<<clsUtil::Tabs(5)<<"Date: "<<clsDate::DateToString(clsDate())<<'\n'<<endl;
}
