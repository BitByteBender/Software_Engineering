#include "../headers/clsLoginScreen.hpp"
#include "../headers/clsmainscreen.hpp"
#include "../headers/global.hpp"
void clsLoginScreen::_SaveToLogFile()
{
  fstream File;
  File.open("Logfile.txt", ios::out | ios::app);

  if (File.is_open()) {
    string Line = clsDate::DateToString(clsDate()) + "#//#" + CurrentUser.GetUsername() + "#//#" + CurrentUser.GetPassword() + "#//#" + to_string(CurrentUser.GetPermissions());
    if (Line != "")
      File<<Line<<'\n';

    File.close();
  }
}

void clsLoginScreen::_Login()
{ 
  bool LoginChecker = false;
  string Username = "", Password = "";
  uint16_t Count = 0;
  
  do {
    if (LoginChecker) {
      cout<<"\nInvalid Username/Password\n";
      ++Count;
      if (Count == 3) {
	cout<<"You exceeed all the attempts\n";
	exit(EXIT_FAILURE);
      }
      cout<<abs(Count - 3)<<" more attempts left\n";
    }
    
    cout<<"Enter a username: ";
    cin>>Username;

    cout<<"Enter a password: ";
    cin>>Password;

    CurrentUser = clsUser::Find(Username, Password);
    LoginChecker = CurrentUser.IsEmpty();
    
  } while (LoginChecker);

  clsMainScreen::ShowMainMenu();
  _SaveToLogFile();
}

void clsLoginScreen::ShowLoginScreen()
{
  _DrawScreenHeader("\t\tLogin Screen");
  _Login();
}
