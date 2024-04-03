#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ws;

enum enMainMenu
{
  View = 1,
  Add = 2,
  Del = 3,
  Update = 4,
  Exit = 5
};

string extraORNot(string build, bool extra)
{
  if (extra) {
    return (build = '\n' + build + '\n');
  } else {
    return (build = build + '\n');
  }
}

string menuBuilder(string style, uint16_t extender, bool extra=false)
{
  uint16_t i = 0;
  string build;

  for (i = 0; i < extender; i++) {
    build = build + style;
  }
  
  return (extraORNot(build, extra));
}

void DisplayMainMenu(string style, uint16_t extender)
{
  string build = menuBuilder(style, extender, true);

  cout<<menuBuilder(style, extender, false)
      <<"\t\t\t\t    Main Menu"
      <<build;

  cout<<"\n\t\t1# View"
      <<" | 2# Add"
      <<" | 3# Delete"
      <<" | 4# Update"
      <<" | 5# Exit"
      <<build
      <<endl;
}

string prompt(const char* Message)
{
  string Input{"empty"};

  cout<<Message;
  getline(cin >> ws, Input);
  
  return (Input);
}

void switchTo()
{
  char Entry = stoi(prompt("[@usr-name] Entry>>: "));
  
  switch ((enMainMenu)Entry) {
  case (enMainMenu::View):
    cout<<">> MainMenu > View > Data\n";
    break;
  case (enMainMenu::Add):
    cout<<">> MainMenu > Add > Data\n";
    break;
  case (enMainMenu::Del):
    cout<<">> MainMenu > Delete > Data\n";
    break;
  case (enMainMenu::Update):
    cout<<">> MainMenu > Update > Data\n";
    break;
  case (enMainMenu::Exit):
    cout<<"Program Terminated\n";
    break;
  default:
    cout<<"Wrong Entry\n";
  }
}

int main(void)
{
  DisplayMainMenu("_", 82);
  switchTo();
  return (0);
}
