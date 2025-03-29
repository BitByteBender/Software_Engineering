#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
  int Val = 0;
  Node *Next = nullptr;
  Node *Prev = nullptr;
};

void Print(Node *Head)
{
  while (Head != nullptr) {
    cout<<Head->Val;
    Head = Head->Next;
    if (Head != nullptr) cout<<", ";
  }
  cout<<endl;
}

void InsertLast(Node *&Head, int Val)
{
  Node *NewNode = nullptr, *Current = nullptr;

  Current = Head;
  
  if (Head == nullptr || Head->Next == nullptr) {
    cout<<"here\n";
    NewNode = new Node();
    NewNode->Val = Val;
    NewNode->Next = nullptr;
    
    if (Current == nullptr) {
      NewNode->Prev = nullptr;
      Head = NewNode;
      delete Current;
    } else {
      Current->Next = NewNode;
      NewNode->Prev = Current;
    }
   
    return;
  }

  while (Current->Next != nullptr) {
    Current = Current->Next;
  }

  NewNode = new Node();
  NewNode->Val = Val;
  NewNode->Next = nullptr;
  NewNode->Prev = Current;
  Current->Next = NewNode;
}

int main(void)
{
  Node *Head = nullptr;

  Node *A = nullptr, *B = nullptr, *C = nullptr;

  A = new Node();
  B = new Node();
  C = new Node();
  
  A->Val = 44;
  B->Val = 63;
  C->Val = 99;

  A->Next = B;
  A->Prev = nullptr;

  B->Next = C;
  B->Prev = A;

  C->Next = nullptr;
  C->Prev = B;

  Head = A;

  Print(Head);

  InsertLast(Head, 73);
  Print(Head);

  InsertLast(Head, 34);
  Print(Head);

  InsertLast(Head, 12);
  Print(Head);

  InsertLast(Head, 19);
  Print(Head);
  
  return (0);
}
