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

void DeleteNode(Node *&Head, Node *&DelNode)
{
  if (Head == nullptr || DelNode == nullptr) return;

  if (Head == DelNode)
    Head = DelNode->Next;

  if (DelNode->Next != nullptr)
    DelNode->Next->Prev = DelNode->Prev;

  if (DelNode->Prev != nullptr)
    DelNode->Prev->Next = DelNode->Next;

  delete DelNode;
}

Node *FindNode(Node *Nd, int Val)
{
  while (Nd != nullptr) {
    if (Nd->Value == Val)
      return (Nd);
    Nd = Nd->Next;
  }

  return (nullptr);
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
  Node *Head = nullptr, *Nd = nullptr;

  InsertFirst(Head, 55);
  Print(Head);

  InsertFirst(Head, 16);
  InsertFirst(Head, 29);
  InsertFirst(Head, 49);
  InsertFirst(Head, 17);
  InsertFirst(Head, 36);
  Print(Head);

  cout<<"\nDeletion:\n";
  Nd = FindNode(Head, 29);
  DeleteNode(Head, Nd);
  Print(Head);

  Nd = FindNode(Head, 17);
  DeleteNode(Head, Nd);
  Print(Head);

  Nd = FindNode(Head, 36);
  DeleteNode(Head, Nd);
  Print(Head);

  Nd = FindNode(Head, 550);
  DeleteNode(Head, Nd);
  Print(Head);

  Nd = FindNode(Head, 55);
  DeleteNode(Head, Nd);
  Print(Head);

  Nd = FindNode(Head, 500);
  DeleteNode(Head, Nd);
  Print(Head);
  
  return (0);
}
