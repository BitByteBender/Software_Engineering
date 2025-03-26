#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
  int value = 0;
  Node *Next = nullptr;
};

void InsertAt(Node *&Head, int Val)
{
  Node *N = new Node();
  
  N->value = Val;
  N->Next = Head;

  Head = N;
}

Node *FindNode(Node *Head, int Value)
{
  while (Head != nullptr) {
    if (Head->value == Value) return (Head);
    Head = Head->Next;
  }
  
  return (nullptr);
}

void Print(Node *Head)
{
  while (Head != nullptr) {
    cout<<Head->value<<' ';
    Head = Head->Next;
    if (Head == nullptr) cout<<endl;
  }
}

int main(void)
{
  Node *Head = nullptr;
  
  InsertAt(Head, 9);
  InsertAt(Head, 23);
  InsertAt(Head, -51);
  InsertAt(Head, 133);
  InsertAt(Head, 99);

  Print(Head);
  
  Node *N = FindNode(Head, 23);

  if (N != nullptr) cout<<"Node Found\n"<<endl;
  else cout<<"Node not found\n"<<endl;
  return (0);
}
