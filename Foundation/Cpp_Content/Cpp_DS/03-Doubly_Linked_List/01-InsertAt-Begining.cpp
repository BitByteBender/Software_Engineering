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

void InsertAtStart(Node *&Head, int Val)
{
  Node *NewNode = new Node();

  NewNode->Val = Val;
  NewNode->Prev = nullptr;
  NewNode->Next = Head;

  if (Head != nullptr)
    Head->Prev = NewNode;
  
  Head = NewNode;
}

void PrintForward(Node *Head)
{
  while (Head != nullptr) {
    cout<<Head->Val;
    if (Head->Next != nullptr) cout<<" | ";
    Head = Head->Next;
  }
  cout<<endl;
}

int main(void)
{
  Node *Head = nullptr;

  InsertAtStart(Head, 15);
  PrintForward(Head);

  InsertAtStart(Head, 26);
  InsertAtStart(Head, 35);
  InsertAtStart(Head, 44);
  InsertAtStart(Head, 53);
  InsertAtStart(Head, 62);
  PrintForward(Head);

  return (0);
}
