#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
  int Value = 0;
  Node *Next = nullptr;
  Node *Prev = nullptr;
};

void InsertFirst(Node *&Head, int Val)
{
  Node *New = new Node();

  New->Value = Val;
  New->Next = Head;
  New->Prev = nullptr;

  if (Head != nullptr)
    Head->Prev = New;
  Head = New;
}

void DeleteNode(Node *&Head, int Val)
{
  Node *Current = nullptr;

  if (Head == nullptr) return;
  
  if (Head->Value == Val) {
    Head = Head->Next;
    Head->Next->Prev = nullptr;
    return;
  }

  Current = Head;

  while (Current->Next != nullptr) {
    if (Current->Next->Value == Val)
      break;
    Current = Current->Next;
  }

  if (Current->Next == nullptr) return;
  
  if (Current->Next->Next == nullptr) {
    Current->Next = nullptr;
  } else {
    Current->Next = Current->Next->Next;
    Current->Next->Next->Prev = Current;
  }
 
}

void Print(Node *Head)
{
  while (Head != nullptr) {
    cout<<Head->Value;
    Head = Head->Next;
    if (Head != nullptr) cout<<", ";
  }
  cout<<endl;
}
 
int main(void)
{
  Node *Head = nullptr;

  InsertFirst(Head, 55);
  Print(Head);

  InsertFirst(Head, 16);
  InsertFirst(Head, 29);
  InsertFirst(Head, 49);
  InsertFirst(Head, 17);
  InsertFirst(Head, 36);
  Print(Head);

  cout<<"\nDeletion:\n";
  DeleteNode(Head, 36);
  Print(Head);

  DeleteNode(Head, 49);
  Print(Head);

  DeleteNode(Head, 55);
  Print(Head);

  DeleteNode(Head, 555);
  Print(Head);
  return (0);
}
