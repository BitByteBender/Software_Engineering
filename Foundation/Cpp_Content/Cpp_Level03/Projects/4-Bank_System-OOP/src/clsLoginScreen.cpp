#include "../headers/clsLoginScreen.hpp"
#include "../headers/clsmainscreen.hpp"
#include "../headers/global.hpp"

void clsLoginScreen::_Login()
{ 
  bool LoginChecker = false;
  string Username = "", Password = "";
  
  do {
    if (LoginChecker) cout<<"\nInvalid Username/Password\n";
    
    cout<<"Enter a username: ";
    cin>>Username;

    cout<<"Enter a password: ";
    cin>>Password;

    CurrentUser = clsUser::Find(Username, Password);
    LoginChecker = CurrentUser.IsEmpty();
    
  } while (LoginChecker);

  clsMainScreen::ShowMainMenu();
}

void clsLoginScreen::ShowLoginScreen()
{
  _DrawScreenHeader("\t\tLogin Screen");
  _Login();
}
