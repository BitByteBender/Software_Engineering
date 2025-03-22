#include "../headers/clsLogFileScreen.hpp"

void clsLogFileScreen::PrintRecord(clsUser::stUserLog UL)
{
  cout<<"| "<<clsUtil::SmartSpacer(UL.DateTime, 35)
      <<"| "<<clsUtil::SmartSpacer(UL.Username, 20)
      <<"| "<<clsUtil::SmartSpacer(UL.Passwd, 15)
      <<"| "<<clsUtil::SmartSpacer(to_string(UL.Permission), 10)<<endl;
}

void clsLogFileScreen::ShowLogFileList()
{
  if (!_CheckAccessRights(clsUser::enPermissions::LogFile))
      return ;
  
  _DrawScreenHeader("\t\tLog File Screen");
  _ShowStats();

  cout<<"__________________________________________________________"
      <<"________________________________________________________\n"
      <<"| Date/Time     "<<clsUtil::Tabs(3)
      <<"| Username     "<<clsUtil::Tabs(1)
      <<"| Password"<<clsUtil::Tabs(1)
      <<"| Permissions"<<clsUtil::Tabs(3)
      <<"\n________________________________________________________"
      <<"__________________________________________________________\n";

  for (const clsUser::stUserLog &Rec:clsUser::LoadLogFile()) {
    PrintRecord(Rec);
  }
  
  cout<<"_________________________________________________________"
      <<"_________________________________________________________\n";
}
