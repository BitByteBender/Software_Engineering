#ifndef CLSMYSTACK_HPP
#define CLSMYSTACK_HPP

#include "clsMyQueue.hpp"

template <class T>
class clsMyStack : public clsMyQueue<T>
{
public:
  void push(T Val);
  T Top();
  T Bottom();

  void InsertAtTop(T Item);
  void InsertAtBottom(T Item);
};

template <class T>
void clsMyStack<T>::push(T Val)
{
  clsMyQueue<T>::InsertAtFront(Val);
}

template <class T>
T clsMyStack<T>::Top()
{
  return (clsMyQueue<T>::front());
}

template <class T>
T clsMyStack<T>::Bottom()
{
  return (clsMyQueue<T>::back());
}

template <class T>
void clsMyStack<T>::InsertAtTop(T Item)
{
  clsMyQueue<T>::InsertAtFront(Item);
}

template <class T>
void clsMyStack<T>::InsertAtBottom(T Item)
{
  clsMyQueue<T>::InsertAtBack(Item);
}
#endif /* CLSMYSTACK_HPP */
