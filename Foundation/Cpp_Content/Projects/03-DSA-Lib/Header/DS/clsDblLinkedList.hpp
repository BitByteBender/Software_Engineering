#ifndef CLSDBLLINKEDLIST_HPP
#define CLSDBLLINKEDLIST_HPP

#include <iostream>

using std::cout;
using std::endl;

//Declartion
template <class T>
class clsDblLinkedList
{
private:
  class _Node
  {
  public:
    T Value;
    _Node *Next = nullptr, *Prev = nullptr;
  };
  
  _Node *Head = nullptr, *Tail = nullptr;

public:
  using Node = _Node;
  
  clsDblLinkedList();
  clsDblLinkedList(Node *&Hd, Node *&Tl);
  
  void InsertAtBegining(T Val);
  Node *Find(T Val);
  void InsertAfter(Node *Next, T Val);
  void InsertAtEnd(T Val);
  void DeleteNode(Node *&DelNode);
  void DeleteFirstNode();
  void DeleteLastNode();
  
  //Printing List
  void PrintList();
  void PrintListBackwards();
};


//Definition
template <class T>
clsDblLinkedList<T>::clsDblLinkedList() : Head(nullptr), Tail(nullptr){};

template <class T>
clsDblLinkedList<T>::clsDblLinkedList(Node *&Hd, Node *&Tl)
  : Head(Hd), Tail(Tl)
{
}

template <class T>
void clsDblLinkedList<T>::InsertAtBegining(T Val)
{
  Node *New = new Node();

  New->Value = Val;
  New->Prev = nullptr;
  New->Next = nullptr;

  if (Head == nullptr) {
    Head = New;
    Head->Next = nullptr;
    Tail = Head;
    Tail->Prev = nullptr;
    return;
  }

  New->Next = Head;
  if (Head != nullptr)
    Head->Prev = New;  

  Head = New;
}

template <class T>
typename clsDblLinkedList<T>::Node *clsDblLinkedList<T>::Find(T Val)
{
  Node *Current = Head;
  
  while (Current != nullptr) {
    if (Current->Value == Val)
      return (Current);
    Current = Current->Next;
  }

  return (nullptr);
}

template <class T>
void clsDblLinkedList<T>::InsertAfter(Node *Current, T Val)
{
  Node *New = nullptr;
  
  if (Current == nullptr) return;

  New = new Node();
  New->Value = Val;
  New->Next = Current->Next;
  New->Prev = Current;
  if (Current->Next != nullptr)
    Current->Next->Prev = New;
  Current->Next = New;
}

template <class T>
void clsDblLinkedList<T>::InsertAtEnd(T Val)
{
  Node *New = new Node(), *TN = nullptr;

  New->Value = Val;
  New->Prev = nullptr;
  New->Next = nullptr;
  
  if (Tail == nullptr) {
    Tail = New;
    Head = Tail;
    Tail->Prev = nullptr;
    Head->Next = nullptr;
    return;
  }

  TN = Tail;
  New->Prev = TN;
  Tail->Next = New;
  New->Next = nullptr;
  Tail = New;
}

template <class T>
void clsDblLinkedList<T>::DeleteNode(Node *&DelNode)
{
  if (DelNode == nullptr) return;

  if (Head == Tail) {
    delete Head;
    Tail = nullptr;
    return;
  }

  Node *Current = DelNode;

  if (Head == Current) {
    Head = Current->Next;
  } else {
    Current->Prev->Next = DelNode->Next;
  }
  
  if (Tail == Current) {
    Tail = Current->Prev;
  } else {
    Current->Next->Prev = DelNode->Prev;
  }
  
  delete DelNode;
}

template <class T>
void clsDblLinkedList<T>::DeleteFirstNode()
{
  if (Head == nullptr) return;

  if (Head->Next == nullptr) {
    Tail = nullptr;
    Head = nullptr;
    return;
  }
  
  Node *Current = Head;

  Current = Current->Next;
  Current->Prev = nullptr;
  Head = Current;
}

template <class T>
void clsDblLinkedList<T>::DeleteLastNode()
{
  if (Tail == nullptr) return;

  if (Tail->Prev == nullptr) {
    Tail = nullptr;
    Head = nullptr;
    return;
  }
  
  Node *Current = Tail;

  Current = Current->Prev;
  Current->Next = nullptr;
  Tail = Current;
}

template <class T>
void clsDblLinkedList<T>::PrintList()
{
  Node *Current = Head;

  if (Current == nullptr) {
    cout<<"<0 Node is found>\n";
    return;
  }
  
  while (Current != nullptr) {
    cout<<Current->Value;
    Current = Current->Next;
    if (Current != nullptr) cout<<" | ";
  }
  cout<<endl;
}

template <class T>
void clsDblLinkedList<T>::PrintListBackwards()
{
  Node *Current = Tail;

  if (Current == nullptr) {
    cout<<"<0 Node is found>\n";
    return;
  }
  
  while (Current != nullptr) {
    cout<<Current->Value;
    Current = Current->Prev;
    if (Current != nullptr) cout<<" | ";
  }
  cout<<endl;
}

#endif /* CLSDBLLINKEDLIST_HPP */
