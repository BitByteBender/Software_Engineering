#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::fstream;
using std::ios;

struct stClientData
{
  string AccNum;
  uint16_t PinCode{0};
  string Fullname;
  string PhoneNum;
  double AccBalance{0.0f};
};

string readText(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin >> std::ws, Text);

  return (Text);
}

vector <string> getData(string Filename)
{
  fstream File;
  vector <string> vClientData;
  
  File.open(Filename, ios::in);

  if (File.is_open()) {
    string line;

    while (getline(File, line)) {
      if (line != "") {
	vClientData.push_back(line);
      }
    }
    File.close();
  }
  return (vClientData);
}


bool checkAccNum(string Text, string AccNum)
{
  return (Text == AccNum);
}

vector <string> splitData(vector <string> &vClientData)
{
  vector <string> vStr;
  string separator{"#//#"};
  string temp;
  
  for (const string &dt : vClientData) {
    temp = dt;
    short position = temp.find(separator);
    while (position != string::npos) {
      vStr.push_back(temp.substr(0, position));
      temp.erase(0, position + separator.length());
      position = temp.find(separator);
    }
    if (temp != "") {
      vStr.push_back(temp);
      temp.clear();
    }
  }

  return (vStr);
}

vector <stClientData> loadClient(stClientData &Client, vector <string> &vStr)
{
  vector <stClientData> vClients;

  unsigned short i = 0;
  
  while (i < vStr.size()) {
    Client.AccNum = vStr[i];
    Client.PinCode = stoi(vStr[++i]);
    Client.Fullname = vStr[++i];
    Client.PhoneNum = vStr[++i];
    Client.AccBalance = stod(vStr[++i]);
    vClients.push_back(Client);
    i++;
  }

  return (vClients);
}

bool checkAccNum(vector <stClientData> &vClients, string Text, stClientData &ClientDt)
{
  
  for (stClientData &Clt : vClients) {
    if (Text == Clt.AccNum) {
      ClientDt = Clt;
      return (true);
    }
  }

  return (false);
}

void printClient(vector <stClientData> &vClients, string Text, stClientData ClientDt)
{
  if (checkAccNum(vClients, Text, ClientDt)) {
    cout<<"\nThese are the client details:\n\n";
    cout<<"Account number: "<<ClientDt.AccNum<<'\n';
    cout<<"Pin code: "<<ClientDt.PinCode<<'\n';
    cout<<"Fullname: "<<ClientDt.Fullname<<'\n';
    cout<<"Phone number: "<<ClientDt.PhoneNum<<'\n';
    cout<<"Account balance: "<<ClientDt.AccBalance<<'\n';
  } else {
    cout<<"\nClient with this Account number ("<<Text<<") is not Found!"<<endl;
  }
}

int main(void)
{
  stClientData Client, ClientDt;
  const string Filename = "Clients/Data";
  vector <string> vClientData, vStr;
  vector <stClientData> vClients;
  string Text = readText("Enter client's account number: ");
  
  vClientData = getData(Filename);
  vStr = splitData(vClientData);

  vClients = loadClient(Client, vStr);
  printClient(vClients, Text, ClientDt);
  return (0);
}
