#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
  double Salary = 0.0;
  Node *Next = nullptr;
};

Node *Find(Node *Nd, double Salary)
{
  while (Nd != nullptr) {
    if (Nd->Salary == Salary)
      return (Nd);
    Nd = Nd->Next;
  }

  return (nullptr);
}

void InsertAtStart(Node *&Head, double Salary)
{
  Node *New = new Node();

  New->Salary = Salary;
  New->Next = Head;
  Head = New;
}

void InsertAfter(Node *Current, double Salary)
{
  Node *New = nullptr;
  
  if (Current == nullptr) {
    cout<<"Current node is null\n";
    return;
  }

  New = new Node();
  
  New->Salary = Salary;
  New->Next = Current->Next;
  Current->Next = New;
}

void InsertAtEnd(Node *&Head, double Salary)
{
  Node *New = new Node(), *Current = nullptr;

  New->Salary = Salary;
  New->Next = nullptr;

  if (Head == nullptr) {
    Head = New;
    return;
  }

  Current = Head;
  while (Current != nullptr) {
    if (Current->Next == nullptr)
      break;
    Current = Current->Next;
  }

  Current->Next = New;
}

void InsertBefore(Node *&Head, Node *NextNode, double Salary)
{
  Node *New = new Node(), *Current = nullptr;

  New->Salary = Salary;
  New->Next = nullptr;

  if (Head == nullptr || Head == NextNode) {
    InsertAtStart(Head, Salary);
    return;
  }

  Current = Head;

  while (Current != nullptr) {
    if (Current->Next == NextNode)
      break;
    Current = Current->Next;
  }

  New->Next = Current->Next;
  Current->Next = New;
}

void DeleteNode(Node *&Head, Node *DelNode)
{
  Node *Current = nullptr;
  
  if (DelNode == nullptr || Head == nullptr) return;
  else if (Head == DelNode) {
    Head = DelNode->Next;
    delete DelNode;
    return;
  }
  
  Current = Head;
  
  while (Current != nullptr) {
    if (Current->Next == DelNode)
      break;
    Current = Current->Next;
  }

  Current->Next = DelNode->Next;
  delete DelNode;
}

void Print(Node *Head)
{
  while (Head != nullptr) {
    cout<<Head->Salary;
    Head = Head->Next;
    if (Head != nullptr) cout<<" | ";
    else cout<<endl;
  }
}

int main(void)
{
  Node *Head = nullptr;

  InsertBefore(Head, nullptr, 213);
  Print(Head);

  InsertBefore(Head, Find(Head, 213), 2985);
  Print(Head);
  
  InsertAtEnd(Head, 777);
  Print(Head);
  
  InsertAtStart(Head, 235);
  InsertAtStart(Head, 980);
  InsertAtStart(Head, 34);
  InsertAtStart(Head, 13);
  InsertBefore(Head, Find(Head, 78), 118);
  InsertAtStart(Head, 72);
  InsertAtStart(Head, 78);
  InsertAtStart(Head, 850);
  Print(Head);
  
  Node *Nd = Find(Head, 34);

  if (Nd != nullptr)
    cout<<"Node Value ("<<Nd->Salary<<") found\n";
  else
    cout<<"Node Value not found\n";

  Nd = Find(Head, 340);

  if (Nd != nullptr)
    cout<<"Node Value ("<<Nd->Salary<<") found\n";
  else
    cout<<"Node Value not found\n";


  Nd = Find(Head, 235);
  InsertAfter(Nd, 19);
  Print(Head);

  Nd = Find(Head, 34);
  InsertAfter(Nd, 36);
  Print(Head);
  
  Nd = Find(Head, 235);
  InsertAfter(Nd, 99);
  Print(Head);
  
  Nd = Find(Head, 740);
  InsertAfter(Nd, 109);
  Print(Head);

  InsertAtEnd(Head, 888);
  Print(Head);

  Nd = Find(Head, 13);
  InsertBefore(Head, Nd, 650);
  Print(Head);

  Nd = Find(Head, 93);
  InsertBefore(Head, Nd, 150);
  Print(Head);

  cout<<"\nDeletion of a node:\n";
  Nd = Find(Head, 777);
  DeleteNode(Head, Nd);
  Print(Head);

  Nd = Find(Head, 150);
  DeleteNode(Head, Nd);
  Print(Head);

  Nd = Find(Head, 850);
  DeleteNode(Head, Nd);
  Print(Head);
  
  return (0);
}
