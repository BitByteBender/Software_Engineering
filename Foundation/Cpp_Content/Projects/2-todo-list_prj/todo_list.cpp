#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ws;

string extraORNot(string build, bool extra)
{
  if (extra) {
    return (build = '\n' + build + '\n');
  } else {
    return (build = build + '\n');
  }
}

string tableauBuilder(string style, uint16_t extender, bool extra=false)
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
  string build = tableauBuilder(style, extender, true);

  cout<<tableauBuilder(style, extender, false)
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

int main(void)
{
  DisplayMainMenu("_", 82);
  return (0);
}
