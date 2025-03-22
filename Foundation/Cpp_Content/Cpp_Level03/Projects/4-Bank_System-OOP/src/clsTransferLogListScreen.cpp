#include "../headers/clsTransferLogListScreen.hpp"

void clsTransferLogList::_PrintTransferLog(clsBankClient::TransferType &Tl)
{
  cout<<"| "<<clsUtil::SmartSpacer(Tl.DateTime, 30)
      <<"| "<<clsUtil::SmartSpacer(Tl.ClientSrc, 18)
      <<"| "<<clsUtil::SmartSpacer(Tl.ClientDst, 23)
      <<"| "<<clsUtil::SmartSpacer(to_string(Tl.Amount), 17)
      <<"| "<<clsUtil::SmartSpacer(to_string(Tl.ClientSrcBalance), 18)
      <<"| "<<clsUtil::SmartSpacer(to_string(Tl.ClientDstBalance), 20)
      <<"| "<<clsUtil::SmartSpacer(Tl.CurrentUsername, 20)<<endl;
}

void clsTransferLogList::ShowTransferLog()
{
  vector <clsBankClient::TransferType> vLogs;
  string Subtitle = "";
  
  vLogs = clsBankClient::GetTransferLogs();
  Subtitle = "\t\t(" + to_string(vLogs.size()) + ") Record(s)";
  
  _DrawScreenHeader("\t   Transfer Log List Screen", Subtitle);
  _ShowStats();

  cout<<"___________________________________________________________________________"
      <<"___________________________________________________________________________\n"
      <<"| Date/Time       "<<clsUtil::Tabs(2)
      <<"| Source Acc "<<clsUtil::Tabs(1)
      <<"| Destination Acc "<<clsUtil::Tabs(1)
      <<"| Amount    "<<clsUtil::Tabs(1)
      <<"| Source Bal "<<clsUtil::Tabs(1)
      <<"| Dest Bal     "<<clsUtil::Tabs(1)
      <<"| User  "<<clsUtil::Tabs(2)
      <<"\n__________________________________________________________________________"
      <<"____________________________________________________________________________\n";

  if (vLogs.size() == 0)
    cout<<"No Record is found\n";
  else {
    for (clsBankClient::TransferType &Rec:vLogs)
      _PrintTransferLog(Rec);
  }
  
  cout<<"___________________________________________________________________________"
      <<"___________________________________________________________________________\n"<<endl;
}
