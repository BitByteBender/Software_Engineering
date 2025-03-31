#ifndef CLSDBLLINKEDLIST_HPP
#define CLSDBLLINKEDLIST_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdint>

using std::cout;
using std::endl;

//Declartion
template <class T>
class clsDblLinkedList
{
private:
  class m_Node
  {
  public:
    T Value;
    m_Node *Next = nullptr, *Prev = nullptr;
  };
  
  m_Node *Head = nullptr, *Tail = nullptr;

protected:
  T m_Size = 0;
  T m_Reverse = false;
  
public:
  using Node = m_Node;
  
  clsDblLinkedList();
  clsDblLinkedList(Node *&Hd, Node *&Tl);
  
  void InsertAtBegining(T Val);
  Node *Find(T Val);
  void InsertAfter(Node *Next, T Val);
  void InsertAtEnd(T Val);
  void DeleteNode(Node *&DelNode);
  void DeleteFirstNode();
  void DeleteLastNode();

  T Size();
  bool IsEmpty();
  void Clear();
  void Reverse();
  void UndoReverse();
  //Printing List
  void PrintList();
  void PrintListBackwards();

  ~clsDblLinkedList();
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
    m_Size++;
    return;
  }

  New->Next = Head;
  if (Head != nullptr)
    Head->Prev = New;  

  Head = New;
  m_Size++;
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
  m_Size++;
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
    m_Size++;
    return;
  }

  TN = Tail;
  New->Prev = TN;
  Tail->Next = New;
  New->Next = nullptr;
  Tail = New;
  m_Size++;
}

template <class T>
void clsDblLinkedList<T>::DeleteNode(Node *&DelNode)
{
  if (DelNode == nullptr) return;

  if (Head == Tail) {
    delete Head;
    Head = nullptr;
    Tail = nullptr;
    m_Size = 0;
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

  m_Size--;
  delete DelNode;
}

template <class T>
void clsDblLinkedList<T>::DeleteFirstNode()
{
  if (Head == nullptr) return;

  if (Head->Next == nullptr) {
    delete Head;
    Tail = nullptr;
    Head = nullptr;
    m_Size = 0;
    return;
  }
  
  Node *Current = Head;
  Current = Current->Next;
  Current->Prev = nullptr;
  Head = Current;
  m_Size--;
}

template <class T>
void clsDblLinkedList<T>::DeleteLastNode()
{
  if (Tail == nullptr) return;

  if (Tail->Prev == nullptr) {
    delete Head;
    Tail = nullptr;
    Head = nullptr;
    m_Size = 0;
    return;
  }
  
  Node *Current = Tail;

  Current = Current->Prev;
  Current->Next = nullptr;
  Tail = Current;
  m_Size--;
}

template <class T>
T clsDblLinkedList<T>::Size()
{
  // Uses Big O(n)
  /*
  Node *Current = Head;
  T Count = 0;
  
  if (First == nullptr) return (Count);

  
  while (Current != nullptr) {
    ++Count;
    Current = Current->Next;
  }
  
  return (Count);
  */
  
  // Uses Big O(1)
  return (m_Size); 
}

template <class T>
bool clsDblLinkedList<T>::IsEmpty()
{
  return (!m_Size);
}

template <class T>
void clsDblLinkedList<T>::Clear()
{
  if (Head == nullptr) return;
  
  while (m_Size > 0)
    DeleteFirstNode();

  Head = nullptr;
  Tail = nullptr;
  delete Head;
  delete Tail;
}

template <class T>
void clsDblLinkedList<T>::Reverse()
{
  Node *Temp = nullptr, *Current = nullptr;
  
  if (Head == nullptr) return;

  Current = Head;
  
  while (Current != nullptr) {
    Temp = Current->Prev;
    Current->Prev = Current->Next;
    Current->Next = Temp;
    Current = Current->Prev;
  }

  if (Temp != nullptr) {
    Tail = Head;
    Head = Temp->Prev;
  }
}

template <class T>
void clsDblLinkedList<T>::PrintList()
{
  Node *Current = Head;
  
  if (Current == nullptr) {
    cout<<"<0 Node found>\n";
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
    cout<<"<0 Node found>\n";
    return;
  }
  
  while (Current != nullptr) {
    cout<<Current->Value;
      Current = Current->Prev;
    
    if (Current != nullptr) cout<<" | ";
  }
  cout<<endl;
}

template <class T>
clsDblLinkedList<T>::~clsDblLinkedList()
{
  Clear();
}
#endif /* CLSDBLLINKEDLIST_HPP */
