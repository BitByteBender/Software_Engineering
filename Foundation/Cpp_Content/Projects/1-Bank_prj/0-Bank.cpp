#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::vector;
using std::fstream;
using std::ios;
using std::ws;

enum enFuncs
{
  Display = 0,
  Insert = 1,
  Update = 2,
  Delete = 3,
  Find = 4,
  Exit = 5
};

struct stClients
{
  string AccountNumber;
  uint16_t PinCode;
  string Fullname, PhoneNumber;
  double AccountBalance;
};

string prompt(const char *Msg)
{
  string Text{"empty"};

  cout<<Msg;
  getline(cin >> ws, Text);

  return (Text);
}

char isUpper(char letter)
{
  return (letter >= char(65) && letter <= char(90));
}

char isLower(char letter)
{
  return (letter >= char(97) && letter <= char(122));
}

bool isLetter(char letter)
{
  return (isUpper(letter) || isLower(letter));
}

uint16_t wordCounter(string Text)
{
  uint16_t i = 0, counter = 0;

  for (i = 0; i < Text.length(); ++i) {
    counter++;
  }

  return (counter);
}

bool formatChecker(string text)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < text.length(); i++) {
    if (wordCounter(text) < 6) {
      cout<<"Name is way too short\n";
      return (false);
    }
    
    if (isLetter(text[i - 2]) && text[i - 1] == ' ' && isLetter(text[i])) {
      for (j = 0; j < text.length(); j++) {
	if (text[j] != ' ' && isLetter(text[j]) == false) {
	  cout<<"Wrong format no numbers are allowed in names\n";
	  return (false);
	}
      }
      return (true);
    }
  }

  
  cout<<"Wrong Format(ex: Jinwoo Sung)\n";
  
  return (false);
}

stClients readClientData()
{
  stClients Client;

  cout<<"Adding New client window:\n\n";
  Client.AccountNumber = prompt("Enter an account number: ");
  Client.PinCode = stoi(prompt("Enter a pin code: "));
  
  do {
    Client.Fullname = prompt("Enter your full name: ");
  } while (!formatChecker(Client.Fullname));

  Client.PhoneNumber = prompt("Enter your phone number: ");
  Client.AccountBalance = stod(prompt("Enter your initial deposit: "));
  
  return (Client);
}

void printClient(stClients Client)
{
  cout<<Client.AccountNumber<<'\n';
  cout<<Client.PinCode<<'\n';
  cout<<Client.Fullname<<'\n';
  cout<<Client.PhoneNumber<<'\n';
  cout<<Client.AccountBalance<<endl;
}

int main(void)
{
  stClients Client;
  
  Client = readClientData();
  printClient(Client);
  return (0);
}
