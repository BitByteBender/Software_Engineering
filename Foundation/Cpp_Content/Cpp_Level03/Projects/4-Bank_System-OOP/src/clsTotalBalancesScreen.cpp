#include "../headers/clsTotalBalancesScreen.hpp"


void clsTotalBalancesScreen::PrintBalancesRecordLine(clsBankClient Client)
{
  cout<<"| "<<setw(15)<<left<<Client.GetAccountNumber();
  cout<<"| "<<setw(20)<<left<<Client.GetFullname();
  cout<<"| "<<setw(12)<<left<<Client.GetBalance();
}

void clsTotalBalancesScreen::ShowTotalBalances()
{
  vector <clsBankClient> vClients = clsBankClient::GetClientList();
  string Title = "\t     Balances List Screen", Subtitle = "\t\t(" + to_string(vClients.size()) + ") Client(s).";

  _DrawScreenHeader(Title, Subtitle);

  cout<<"\n______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;

  cout<<"| "<<left<<setw(15)<<"Account Number";
  cout<<"| "<<left<<setw(20)<<"Client Name";
  cout<<"| "<<left<<setw(12)<<"Balance";
  cout<<"\n______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;

  double TotalBalances = clsBankClient::GetTotalBalances();
  
  if (vClients.size() == 0)
    cout<<clsUtil::Tabs(3)<<"No Clients Available In the System!";
  else {
    for (const clsBankClient &Rec:vClients) {
      PrintBalancesRecordLine(Rec);
      cout<<endl;
    }
  }
  cout<<"______________________________________________________";
  cout<<"______________________________________________________\n"<<endl;
  cout<<"Total Balances = "<<TotalBalances<<endl;
}
