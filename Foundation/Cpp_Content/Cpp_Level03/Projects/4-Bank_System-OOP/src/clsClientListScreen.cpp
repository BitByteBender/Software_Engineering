#include "../headers/clsClientListScreen.hpp"

void clsClientListScreen::PrintClientRecordLine(clsBankClient Client)
{
  cout<<"| "<<setw(15)<<left<<Client.GetAccountNumber();
  cout<<"| "<<setw(20)<<left<<Client.GetFullname();
  cout<<"| "<<setw(12)<<left<<Client.GetPhonenum();
  cout<<"| "<<setw(20)<<left<<Client.GetEmail();
  cout<<"| "<<setw(10)<<left<<Client.GetPincode();
  cout<<"| "<<setw(12)<<left<<Client.GetBalance();
}

void clsClientListScreen::ShowClientsList()
{
  if (!_CheckAccessRights(clsUser::enPermissions::ListClients))
      return ;
  
  vector <clsBankClient> vClients = clsBankClient::GetClientList();
  string Title = "\t     Client List Screen", Subtitle = "\t\t(" + to_string(vClients.size()) + ") Client(s).";

  _DrawScreenHeader(Title, Subtitle);

  cout<<"\n______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;

  cout<<"| "<<left<<setw(15)<<"Account Number";
  cout<<"| "<<left<<setw(20)<<"Client Name";
  cout<<"| "<<left<<setw(12)<<"Phone";
  cout<<"| "<<left<<setw(20)<<"Email";
  cout<<"| "<<left<<setw(10)<<"Pin Code";
  cout<<"| "<<left<<setw(12)<<"Balance";
  cout<<"\n______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;

  if (vClients.size() == 0)
    cout<<clsUtil::Tabs(3)<<"No Clients Available In the System!";
  else {
    for (const clsBankClient &Rec:vClients) {
      PrintClientRecordLine(Rec);
      cout<<endl;
    }
  }
  cout<<"______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;
}
