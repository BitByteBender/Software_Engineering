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

void DeleteNode(Node *&Head, double Salary)
{
  Node *Current = nullptr, *Next = nullptr;

  if (Head == nullptr) return;
  else if (Head->Salary == Salary) {
    Current = Head;
    Head = Current->Next;
    delete Current;
    return ;
  }

  Current = Head;
  Next = Current->Next;
  if (Current->Next->Salary == Salary) {
    Current->Next = Next->Next;
  } else {
    
    while (Current->Next != nullptr) {
      if (Current->Next->Salary == Salary) {
	Current->Next = Next->Next;
	break;
      }
      Current = Current->Next;
      Next = Current->Next;
    }
    
  }
  delete Next;
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
  DeleteNode(Head, 777);
  Print(Head);

  DeleteNode(Head, 150);
  Print(Head);

  DeleteNode(Head, 850);
  Print(Head);

  DeleteNode(Head, 8500);
  Print(Head);

  DeleteNode(Head, 19);
  Print(Head);

  DeleteNode(Head, 72);
  Print(Head);

  DeleteNode(Head, 78);
  Print(Head);

  DeleteNode(Head, 2985);
  Print(Head);

  DeleteNode(Head, 5000);
  Print(Head);

  DeleteNode(Head, 888);
  Print(Head);

  DeleteNode(Head, 235);
  Print(Head);

  DeleteNode(Head, 13);
  Print(Head);

  DeleteNode(Head, 650);
  Print(Head);

  DeleteNode(Head, 118);
  Print(Head);

  DeleteNode(Head, 8880);
  Print(Head);

  DeleteNode(Head, 36);
  Print(Head);

  DeleteNode(Head, 13);
  Print(Head);

  DeleteNode(Head, 99);
  Print(Head);

  DeleteNode(Head, 980);
  Print(Head);

  DeleteNode(Head, 34);
  Print(Head);

  DeleteNode(Head, 213);
  Print(Head);
  cout<<"Above is a Deletion of all nodes\n";
  DeleteNode(Head, 2130);
  Print(Head);

  InsertAtEnd(Head, 225);
  Print(Head);

  DeleteNode(Head, 225);
  Print(Head);
  
  if (Find(Head, 225) != nullptr) cout<<"Node 225 Found\n";
  else cout<<"Node 225 Not Found\n";
  
  return (0);
}
