#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string readText(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin, Text);

  return (Text);
}

int main(void)
{
  string Text = readText("Enter a text: ");
 
  for (char chars : Text) {
    cout<<chars<<'\n';
  }


  cout<<endl;
 
  for (int chars : Text) {
    cout<<char(chars)<<'\n';
  }

  return (0);
}
