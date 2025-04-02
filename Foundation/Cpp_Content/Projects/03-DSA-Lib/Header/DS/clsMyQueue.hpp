#ifndef CLSMYQUEUE_HPP
#define CLSMYQUEUE_HPP

#include "clsDblLinkedList.hpp"

template <class T>
class clsMyQueue
{
protected:
  clsDblLinkedList<T> MyList;
  
public:
  void push(T Val);
  short Size();
  T front();
  T back();
  void Print();
  void pop();
  bool IsEmpty();

  void Reverse();
  T GetItem(T Item);
  void UpdateItem(T Index, T Val);
  void InsertAfter(T Index, T Item);
  void InsertAtFront(T Item);
  void InsertAtBack(T Item);
  void Clear();
};

template <class T>
void clsMyQueue<T>::push(T Val)
{
  MyList.InsertAtEnd(Val);
}

template <class T>
short clsMyQueue<T>::Size()
{
  return (MyList.Size());
}

template <class T>
T clsMyQueue<T>::front()
{
  return (MyList.GetItem(0));
}

template <class T>
T clsMyQueue<T>::back()
{
  return (MyList.GetItem(Size()-1));
}

template <class T>
void clsMyQueue<T>::Print()
{
  MyList.PrintList();
}

template <class T>
void clsMyQueue<T>::pop()
{
  MyList.DeleteFirstNode();
}

template <class T>
bool clsMyQueue<T>::IsEmpty()
{
  return (MyList.IsEmpty());
}

template <class T>
void clsMyQueue<T>::Reverse()
{
  MyList.Reverse();
}

template <class T>
T clsMyQueue<T>::GetItem(T Item)
{
  return (MyList.GetItem(Item));
}

template <class T>
void clsMyQueue<T>::UpdateItem(T Index, T Val)
{
  MyList.UpdateItem(Index, Val);
}

template <class T>
void clsMyQueue<T>::InsertAfter(T Index, T Item)
{
  MyList.InsertAfter(Index, Item);
}

template <class T>
void clsMyQueue<T>::InsertAtFront(T Item)
{
  MyList.InsertAtBegining(Item);
}

template <class T>
void clsMyQueue<T>::InsertAtBack(T Item)
{
  push(Item);
}

template <class T>
void clsMyQueue<T>::Clear()
{
  MyList.Clear();
}
#endif /* CLSMYQUEUE_HPP */
