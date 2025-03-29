#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
  int value;
  Node *Next;
  Node *Prev;
};

void InsertAtHead(Node *&Head, Node *&Tail, int val)
{
  Node *New = new Node();

  New->value = val;
  New->Prev = nullptr;
  
  if (Head == nullptr) {
    Head = New;
    Head->Next = nullptr;
    Tail = Head;
    Tail->Prev = nullptr;
    return;
  }

  New->Next = Head;
  if (Head != nullptr) {
    Head->Prev = New;
  }

  Head = New;
}

void InsertAtTail(Node *&Head, Node *&Tail, int val)
{
  Node *New = new Node();

  New->value = val;
  New->Prev = nullptr;
  New->Next = nullptr;
  
  if (Tail == nullptr && Head == nullptr) {
    Head = New;
    Tail = New;
    return;
  } else {
    Node *Current = Tail;
    
    New->Prev = Tail;
    Tail = New;
    Current->Next = New;
  }
}

void DeleteLastNode(Node *&Head, Node *&Tail, int val)
{
  Node *Current = nullptr;

  if (Tail == nullptr || Head == nullptr) return;
  
  if (Tail->value == val) {
    Current = Tail;
    if (Tail->Prev == nullptr) {
      Tail = nullptr;
      Head = nullptr;
      delete Current;
      return ;
    }
    Tail = Tail->Prev;

    Current->Prev->Next = nullptr;
    Current->Prev = Head;
  }
}

void Print(Node *Head)
{
  while (Head != nullptr) {
    cout<<Head->value;
    Head = Head->Next;
    if (Head != nullptr) cout<<", ";
  }
  cout<<endl;
}

void PrintBackwards(Node *Tail)
{
  while (Tail != nullptr) {
    cout<<Tail->value;
    Tail = Tail->Prev;
    if (Tail != nullptr) cout<<", ";
  }
  cout<<endl;
}

int main(void)
{
  Node *Head = nullptr, *Tail = nullptr;

  cout<<"Insert at head:\n";
  InsertAtHead(Head, Tail, 10);
  Print(Head);

  InsertAtHead(Head, Tail, 20);
  InsertAtHead(Head, Tail, 30);
  InsertAtHead(Head, Tail, 40);
  InsertAtHead(Head, Tail, 50);
  InsertAtHead(Head, Tail, 60);
  Print(Head);
  PrintBackwards(Tail);

  cout<<"\nInsert at last:\n";
  InsertAtTail(Head, Tail, 55);
  Print(Head);
  PrintBackwards(Tail);

  InsertAtTail(Head, Tail, 550);
  Print(Head);
  PrintBackwards(Tail);

  InsertAtTail(Head, Tail, 505);
  Print(Head);
  PrintBackwards(Tail);

  cout<<"\nDeletion of  last node:\n";
  DeleteLastNode(Head, Tail, 505);
  Print(Head);
  PrintBackwards(Tail);

  DeleteLastNode(Head, Tail, 550);
  Print(Head);
  PrintBackwards(Tail);

  DeleteLastNode(Head, Tail, 502);
  Print(Head);
  PrintBackwards(Tail);

  DeleteLastNode(Head, Tail, 55);
  Print(Head);
  PrintBackwards(Tail);

  DeleteLastNode(Head, Tail, 10);
  Print(Head);
  PrintBackwards(Tail);

  DeleteLastNode(Head, Tail, 20);
  Print(Head);
  PrintBackwards(Tail);

  DeleteLastNode(Head, Tail, 30);
  Print(Head);
  PrintBackwards(Tail);

  DeleteLastNode(Head, Tail, 40);
  Print(Head);
  PrintBackwards(Tail);

  DeleteLastNode(Head, Tail, 50);
  Print(Head);
  PrintBackwards(Tail);

  DeleteLastNode(Head, Tail, 60);
  Print(Head);
  PrintBackwards(Tail);

  DeleteLastNode(Head, Tail, 69);
  Print(Head);
  PrintBackwards(Tail);
  
  return (0);
}
