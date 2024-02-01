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

bool nameFormatChecker(string text)
{
  uint16_t i = 0, j = 0;

  for (i = 0; i < text.length(); i++) {
    if (wordCounter(text) < 6) {
      cout<<"Name is way too short\n";
      return (false);
    }
    
    if (text[i - 1] == ' ' && isLetter(text[i])) {
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

bool accBalanceFormatChecker(string text)
{
  uint16_t i = 0;
  
  for (i = 0; i < text.length(); ++i) {
    if (isLetter(text[i])) {
      cout<<"Account Balance should be a number\n";
      return (false);
    }
  }
  return (true);
}

stClients readClientData()
{
  stClients Client;
  string AccBalance;
  
  cout<<"Adding New client window:\n\n";
  
  do {
    Client.AccountNumber = prompt("Enter an account number: ");
  } while (!isUpper(Client.AccountNumber[0]) || wordCounter(Client.AccountNumber) < 4);

  Client.PinCode = stoi(prompt("Enter a pin code: "));
  
  do {
    Client.Fullname = prompt("Enter your full name: ");
  } while (!nameFormatChecker(Client.Fullname));

  Client.PhoneNumber = prompt("Enter your phone number: ");

  do {
   AccBalance = prompt("Enter your initial deposit: ");
  } while (!accBalanceFormatChecker(AccBalance));

  Client.AccountBalance = stod(AccBalance);
  
  return (Client);
}

vector <stClients> vecFillerWithClients(stClients &Client, bool CheckCase=false)
{
  vector <stClients> vClients;
  char operation = 'N';

  do {
    Client = readClientData();
    vClients.push_back(Client);
    
    operation = char(prompt("Do you want to add more clients?")[0]);
    
    if (operation == 'y' || operation == 'Y') {
      CheckCase = true;
    } else {
      CheckCase = false;
    }
  } while (CheckCase);
  
  return (vClients);
}

void printClient(stClients Client)
{
  cout<<"Account number: "<<Client.AccountNumber<<'\n';
  cout<<"Pin code: "<<Client.PinCode<<'\n';
  cout<<"Fullname: "<<Client.Fullname<<'\n';
  cout<<"Phone number: "<<Client.PhoneNumber<<'\n';
  cout<<"Account balance: "<<Client.AccountBalance<<endl;
}

int main(void)
{
  stClients Client;
  vector <stClients> vClients;
  
  vClients = vecFillerWithClients(Client);

  for (const stClients &C : vClients) {
    printClient(C);
    cout<<endl;
  }
  
  return (0);
}
