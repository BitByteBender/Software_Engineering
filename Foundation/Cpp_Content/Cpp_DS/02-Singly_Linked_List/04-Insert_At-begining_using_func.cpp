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

void InsertAtBegining(Node *&Head, Node Person)
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
    cout<<Head->P->Name<<" | "<<Head->P->Age<<'\n';
    Head = Head->Next;
  }
}

int main(void)
{
  Node *Head = nullptr;
  Node Person;
  
  Person.P->Name = "Souf";
  Person.P->Age = 30;
  InsertAtBegining(Head, Person);

  Person.P->Name = "Sdg";
  Person.P->Age = 31;
  InsertAtBegining(Head, Person);
  
  Person.P->Name = "SS";
  Person.P->Age = 20;
  InsertAtBegining(Head, Person);

  Print(Head);
  
  return 0;
}
