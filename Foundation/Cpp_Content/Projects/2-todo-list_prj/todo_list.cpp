#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ios;
using std::ws;

struct stContents
{
  string Id;
  string Description;
};
  
struct stTickets
{
  string ticketId;
  stContents Content;
  string date;
};

string promptReader(const char *Msg)
{
  string Prompt{"empty"};

  cout<<Msg;
  getline(cin >> ws, Prompt);

  return (Prompt);
}

bool isIdUnique(vector <stTickets> &vTickets, string ticketId)
{

  for (const stTickets &Cnt:vTickets) {
    if (Cnt.ticketId == ticketId)
      return (false);
  }
  
  return (true);
}

stTickets readTicket(vector <stTickets> &vTickets)
{
  stTickets Ticket;

  Ticket.ticketId = promptReader("Enter a ticket id: ");
  
  while (!isIdUnique(vTickets, Ticket.ticketId)) {
      cout<<"Ticket ID is not unique!\n";
      Ticket.ticketId = promptReader(">> re-Enter a fresh ticket id: ");
  }
  
  Ticket.Content.Description = promptReader("Enter a content: ");
  Ticket.date = promptReader("Enter a date: ");
  
  return (Ticket);
}

vector <stTickets> saveTickets(char loader='y')
{
  stTickets Ticket;
  vector <stTickets> vTickets;
  
  do {
    Ticket = readTicket(vTickets);
    
    vTickets.push_back(Ticket);
    
    loader = char(promptReader("Do you want to keep saving?(y | n): ")[0]);
    cout<<'\n';
  } while (loader == 'y' || loader == 'Y');


  return (vTickets);
}

int main(void)
{
  vector <stTickets> t = saveTickets();
  
  return (0);
}
