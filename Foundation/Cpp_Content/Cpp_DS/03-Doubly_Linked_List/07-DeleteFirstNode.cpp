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

void DeleteFirstNode(Node *&Head)
{
  if (Head == nullptr) return;

  Head = Head->Next;
  if (Head != nullptr) {
    Head->Prev = nullptr;
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
  DeleteFirstNode(Head);
  Print(Head);


  DeleteFirstNode(Head);
  Print(Head);


  DeleteFirstNode(Head);
  Print(Head);


  DeleteFirstNode(Head);
  Print(Head);


  DeleteFirstNode(Head);
  Print(Head);

  DeleteFirstNode(Head);
  Print(Head);
  
  return (0);
}
