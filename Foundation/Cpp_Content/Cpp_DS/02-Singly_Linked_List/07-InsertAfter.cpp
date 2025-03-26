#include <iostream>
#include <cstdint>

using std::cout;
using std::endl;
using std::string;

class Node
{
private:
  struct stPerson
  {
    string Name;
    uint16_t Age;
  };
public:
  stPerson P;
  Node *Next;
};

void InsertAtStart(Node *&Head, Node PersonData)
{
  Node *N = new Node();

  N->P.Name = PersonData.P.Name;
  N->P.Age = PersonData.P.Age;
  N->Next = Head;

  Head = N;
}

void Print(Node *Head)
{
  while (Head != nullptr) {
    cout<<'('<<Head->P.Name<<" | "<<Head->P.Age<<')';
    Head = Head->Next;
    if (Head != nullptr) cout<<", ";
  }
  cout<<endl;
}

Node *FindNode(Node *Head, Node PersonData)
{
  while (Head != nullptr) {
    if (Head->P.Name == PersonData.P.Name && Head->P.Age == PersonData.P.Age)
      return (Head);

    Head = Head->Next;
  }

  return (nullptr);
}

void InsertAfter(Node *prevNode, Node PersonData)
{
  Node *New_Node = nullptr;

  if (prevNode != nullptr)
    New_Node = new Node();
  else return;

  New_Node->P.Name = PersonData.P.Name;
  New_Node->P.Age = PersonData.P.Age;
  New_Node->Next = prevNode->Next;
  prevNode->Next = New_Node;
}

int main(void)
{
  Node *Head = nullptr, *Nd = nullptr;
  Node PersonData;

  PersonData.P.Name = "Maria";
  PersonData.P.Age = 27;
  InsertAtStart(Head, PersonData);

  PersonData.P.Name = "Marian";
  PersonData.P.Age = 31;
  InsertAtStart(Head, PersonData);

  PersonData.P.Name = "Randi";
  PersonData.P.Age = 25;
  InsertAtStart(Head, PersonData);

  PersonData.P.Name = "Kronos";
  PersonData.P.Age = 115;
  InsertAtStart(Head, PersonData);

  Print(Head);

  PersonData.P.Name = "Randi";
  PersonData.P.Age = 25;
  Nd = FindNode(Head, PersonData);

  if (Nd != nullptr)
    cout<<"-> Node has been found!\n";
  else
    cout<<"-> Node not found!\n";

  PersonData.P.Name = "SJW";
  PersonData.P.Age = 24;
  InsertAfter(Nd, PersonData);
  
  Print(Head);
  return (0);
}

