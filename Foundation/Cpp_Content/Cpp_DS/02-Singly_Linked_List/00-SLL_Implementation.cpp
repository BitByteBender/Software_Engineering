#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
  int16_t Dt = 0;
  Node *Next = nullptr;
};

int main(void)
{
  Node *Head = nullptr;
  
  Node *NodeA = nullptr;
  Node *NodeB = nullptr;
  Node *NodeC = nullptr;
  Node *NodeD = nullptr;
  Node *NodeE = nullptr;

  // Allocating on the heap
  NodeA = new Node();
  NodeB = new Node();
  NodeC = new Node();
  NodeD = new Node();
  NodeE = new Node();

  // Inserting values
  (*NodeA).Dt = 55;
  NodeB->Dt = 78;
  NodeC->Dt = -99;
  NodeD->Dt = 115;
  NodeE->Dt = 225;

  // Linking nodes
  NodeA->Next = NodeB;
  (*NodeB).Next = NodeC;
  NodeC->Next = *&NodeD;
  NodeD->Next = NodeE;

  //Linking the end of the list
  NodeE->Next = nullptr;

  //Linking with the master/iterator/jumper/traverser
  Head = NodeA;
  while (Head != nullptr) {
    cout<<Head->Dt<<' ';
    Head = Head->Next;
  }

  cout<<endl;
  return (0);
}
