#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Node
{
public:
  string Str = "";
  Node *Next = nullptr;
};

int main(void)
{
  Node *Head{nullptr};

  Node *Node1{nullptr};
  Node *Node2{nullptr};
  Node *Node3{nullptr};

  Node1 = new Node();
  Node2 = new Node();
  Node3 = new Node();

  Node1->Next = Node2;
  Node2->Next = Node3;
  Node3->Next = nullptr;

  Node1->Str = "Node1";
  Node2->Str = "Node2";
  Node3->Str = "Node3";

  Head = Node1;
  Node *Node4{nullptr};

  while (Head != nullptr) {
    Head = Head->Next;
    
    if (Head->Next == nullptr) {
      Node4 = new Node();
      Node4->Str = "Node4";
      Node4->Next = nullptr;
      Head = Node4;
      break;
    }
  }
  
  cout<<Head->Str<<'\n';
  //Head = Node1;
  while (Head != nullptr) {
    cout<<Head->Str<<' ';
    Head = Head->Next;
  }

  /*
  while (Head->Str != "Node4") {
    cout<<Head->Str<<' ';
    if (Head->Next->Next == nullptr) {
      Node4 = new Node();
      Node4->Str = "Node4";
      Node4->Next = Head->Next->Next;
      Head->Next->Next = Node4;
    }
    
    Head = Head->Next;
    if (Head == nullptr || Head->Next == nullptr) break;
  }*/


  cout<<endl;
  return (0);
}
