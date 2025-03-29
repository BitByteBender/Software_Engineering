#include <iostream>

using std::cout;
using std::endl;

class Node
{
public:
  int Value = 0;
  Node *Prev = nullptr;
  Node *Next = nullptr;
};

int main(void)
{
  Node *Head = nullptr, *Tail = nullptr;

  Node *N0 = nullptr, *N1 = nullptr, *N2 = nullptr, *N3 = nullptr;

  N0 = new Node();
  N1 = new Node();
  N2 = new Node();
  N3 = new Node();

  N0->Value = 15;
  N1->Value = 21;
  N2->Value = 85;
  N3->Value = -99;

  N0->Next = N1;
  N1->Next = N2;
  N2->Next = N3;
  N3->Next = nullptr;

  N0->Prev = nullptr;
  N1->Prev = N0;
  N2->Prev = N1;
  N3->Prev = N2;

  Head = N0;
  Tail = N3;

  while (Head != nullptr && Tail != nullptr) {
    cout<<"Head: "<<Head->Value<<" > | < ";
    Head = Head->Next;

    cout<<"Tail: "<<Tail->Value<<" | ";
    Tail = Tail->Prev;
  }

  cout<<endl;
  
  return (0);
}
