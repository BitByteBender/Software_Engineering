#include <iostream>
#include <cstdint>

using std::string;
using std::endl;
using std::cout;


class Node
{
private:
  struct stPerson
  {
    string Name = "";
    uint16_t Age = 0;
  };
public:
  stPerson *P = new stPerson();
  Node *Next;
};

void InsertAtStart(Node *&Head, Node Person)
{
  Node *New_Node = new Node();
  
  New_Node->P->Name = Person.P->Name;
  New_Node->P->Age = Person.P->Age;
  New_Node->Next = Head;
  Head = New_Node;
}

void Print(Node *Head)
{
  while (Head != nullptr) {
    cout<<'('<<Head->P->Name<<" | "<<Head->P->Age<<')';
    Head = Head->Next;
    if (Head != nullptr) cout<<", ";
  }
  cout<<endl;
}

void InsertAtEnd(Node *Head, Node Person)
{
  Node *New_Node = new Node();
  
  New_Node->P->Name = Person.P->Name;
  New_Node->P->Age = Person.P->Age;

  while (Head != nullptr) {
    Head = Head->Next;
    if (Head->Next == nullptr) break;
  }

  New_Node->Next = Head->Next;
  Head->Next = New_Node;
}

Node *FindNode(Node *Head, Node Person)
{
  while (Head != nullptr) {
    if ((Head->P->Name == Person.P->Name) && (Head->P->Age == Person.P->Age))
      return (Head);
    Head = Head->Next;
  }
  
  return (nullptr);
}

void InsertBefore(Node *Head, Node *prevNode, Node Person)
{
  Node *New_Node = new Node();

  while (Head != nullptr) {
    if (Head->Next == prevNode)
      break;
    Head = Head->Next;
  }

  New_Node->P->Name = Person.P->Name;
  New_Node->P->Age = Person.P->Age;
  
  New_Node->Next = prevNode;
  Head->Next = New_Node;
}

int main(void)
{
  Node *Head = nullptr, *Nd = nullptr;
  Node Person;
  
  Person.P->Name = "Souf";
  Person.P->Age = 30;
  InsertAtStart(Head, Person);

  Person.P->Name = "Sdg";
  Person.P->Age = 31;
  InsertAtStart(Head, Person);

  Person.P->Name = "SSR";
  Person.P->Age = 25;
  InsertAtStart(Head, Person);
  
  Person.P->Name = "SS";
  Person.P->Age = 20;
  InsertAtStart(Head, Person);

  Print(Head);

  Person.P->Name = "Newsom";
  Person.P->Age = 99;
  InsertAtEnd(Head, Person);

  Person.P->Name = "Lara";
  Person.P->Age = 21;
  InsertAtEnd(Head, Person);

  Person.P->Name = "Ola";
  Person.P->Age = 67;
  InsertAtEnd(Head, Person);

  Person.P->Name = "Meha";
  Person.P->Age = 55;
  InsertAtEnd(Head, Person);

  Person.P->Name = "Mailo";
  Person.P->Age = 85;
  InsertAtEnd(Head, Person);

  Person.P->Name = "Ritaa";
  Person.P->Age = 5;
  InsertAtEnd(Head, Person);

  Person.P->Name = "Ali";
  Person.P->Age = 15;
  InsertAtEnd(Head, Person);

  Person.P->Name = "Zak";
  Person.P->Age = 26;
  InsertAtEnd(Head, Person);

  Print(Head);

  Person.P->Name = "Ritaa";
  Person.P->Age = 5;
  Nd = FindNode(Head, Person);
  
  if (Nd != nullptr)
    cout<<"Node is found\n";
  else
    cout<<"Node is not found\n";

  Person.P->Name = "Zaki";
  Person.P->Age = 26;
  Nd = FindNode(Head, Person);
  
  if (Nd != nullptr)
    cout<<"Node is found\n";
  else
    cout<<"Node is not found\n";

  Person.P->Name = "Zak";
  Person.P->Age = 26;
  Nd = FindNode(Head, Person);
  
  Person.P->Name = "Malak";
  Person.P->Age = 32;
  InsertBefore(Head, Nd, Person);

  Print(Head);
  return (0);
}
