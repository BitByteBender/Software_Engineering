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

Node *FindNode(Node *Nd, int Val)
{
  while (Nd != nullptr) {
    if (Nd->Val == Val) return (Nd);
    Nd = Nd->Next;
  }

  return (nullptr);
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
  Node *Head = nullptr, *Nd = nullptr;

  InsertAtStart(Head, 15);
  PrintForward(Head);

  InsertAtStart(Head, 26);
  InsertAtStart(Head, 35);
  InsertAtStart(Head, 44);
  InsertAtStart(Head, 53);
  InsertAtStart(Head, 62);
  PrintForward(Head);

  Nd = FindNode(Head, 44);
  if (Nd != nullptr) cout<<"Node 44 is found\n";
  else cout<<"Node 44 is not found\n";

  Nd = FindNode(Head, 35);
  if (Nd != nullptr) cout<<"Node 35 is found\n";
  else cout<<"Node 35 is not found\n";

    Nd = FindNode(Head, 26);
  if (Nd != nullptr) cout<<"Node 26 is found\n";
  else cout<<"Node 26 is not found\n";

    Nd = FindNode(Head, 53);
  if (Nd != nullptr) cout<<"Node 53 is found\n";
  else cout<<"Node 53 is not found\n";

    Nd = FindNode(Head, 18);
  if (Nd != nullptr) cout<<"Node 18 is found\n";
  else cout<<"Node 18 is not found\n";

  
  return (0);
}
