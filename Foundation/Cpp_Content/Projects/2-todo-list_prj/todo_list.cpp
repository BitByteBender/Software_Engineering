#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ws;


string prompt(const char* Message)
{
  string Input{"empty"};

  cout<<Message;
  getline(cin >> ws, Input);
  
  return (Input);
}

int main(void)
{
  string InputTest = prompt("Enter a text: ");

  cout<<InputTest<<endl;
  return (0);
}

