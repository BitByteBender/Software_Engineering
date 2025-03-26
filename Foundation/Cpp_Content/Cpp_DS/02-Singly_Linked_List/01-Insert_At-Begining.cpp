#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
  float Value = 0.f;
  Node *Next = nullptr;
};

int main(void)
{
  Node *Head{nullptr};

  Node *Node1{nullptr}, *Node2{nullptr}, *Node3{nullptr};

  Node1 = new Node(), Node2 = new Node(), Node3 = new Node();

  Node1->Next = Node2;
  Node2->Next = Node3;
  Node3->Next = nullptr;

  Head = Node1;

  if (Head != nullptr)
    Head->Value = 550.f;
  
  cout<<Head->Value<<'\n';
  cout<<Node1->Value<<endl;

  Node *Node0;
  
  if (Head != nullptr && Head->Next != nullptr) {
    Node0 = new Node();
    Node0->Next = Head;
    Head = Node0;
  }

  Node0->Value = 25.f;
  Node2->Value = 35.f;
  Node3->Value = -5.f;
  
  cout<<"Node0: "<<Node0->Value
      <<" | Head: "<<Head->Value
      <<" | Node1: "<<Node1->Value
      <<" | Node2: "<<Node2->Value
      <<" | Node3: "<<Node3->Value<<endl;

  while (Head != nullptr) {
    cout<<Head->Value<<' ';
    Head = Head->Next;
  }
  cout<<'\n';
  return (0);
}
