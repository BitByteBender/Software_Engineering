#include "Header/DS/clsDblLinkedList.hpp"

int main(void)
{
  clsDblLinkedList<int> MyDblLinkedList;

  if (MyDblLinkedList.IsEmpty())
    cout<<"Yes, it is empty\n";
  else
    cout<<"No, It is not empty\n";
  
  MyDblLinkedList.InsertAtBegining(20);
  MyDblLinkedList.InsertAtBegining(30);
  MyDblLinkedList.InsertAtBegining(40);
  MyDblLinkedList.InsertAtBegining(50);
  
  
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();
  
  clsDblLinkedList<int>::Node *N1 = MyDblLinkedList.Find(30);

  if (N1 != nullptr)
    cout<<"\nNode with value 30 is found!\n";
  else
    cout<<"\nNode with value 30 is not found!\n"<<endl;

  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.InsertAfter(N1, 500);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.InsertAtEnd(600);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.InsertAtEnd(700);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.InsertAtEnd(800);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.InsertAtEnd(900);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  cout<<"\nNodes Deletion:\n";
  N1 = MyDblLinkedList.Find(30);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  N1 = MyDblLinkedList.Find(40);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  N1 = MyDblLinkedList.Find(50);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  N1 = MyDblLinkedList.Find(500);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  N1 = MyDblLinkedList.Find(900);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  N1 = MyDblLinkedList.Find(800);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();


  N1 = MyDblLinkedList.Find(300);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  N1 = MyDblLinkedList.Find(600);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  N1 = MyDblLinkedList.Find(20);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  N1 = MyDblLinkedList.Find(700);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  cout<<"\nRetest:\n";
  MyDblLinkedList.InsertAtBegining(999);

  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  N1 = MyDblLinkedList.Find(999);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();


  MyDblLinkedList.InsertAtEnd(25);
  MyDblLinkedList.InsertAtBegining(777);
  
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  N1 = MyDblLinkedList.Find(777);
    
  MyDblLinkedList.DeleteNode(N1);
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();


  cout<<"\nNode Deletion(First):\n";
  MyDblLinkedList.InsertAtBegining(10);

  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.DeleteFirstNode();
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();


  MyDblLinkedList.InsertAtEnd(15);
  MyDblLinkedList.InsertAtBegining(30);
  
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.DeleteFirstNode();
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.InsertAtEnd(45);
  MyDblLinkedList.InsertAtBegining(65);
  MyDblLinkedList.InsertAtBegining(75);
  
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.DeleteFirstNode();
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();
  
  cout<<"\nNode Deletion(Last):\n";
  MyDblLinkedList.InsertAtBegining(80);

  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.DeleteLastNode();
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();


  MyDblLinkedList.InsertAtEnd(53);
  MyDblLinkedList.InsertAtBegining(360);
  
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.DeleteLastNode();
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.InsertAtEnd(425);
  MyDblLinkedList.InsertAtBegining(685);
  MyDblLinkedList.InsertAtBegining(725);
  
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.DeleteLastNode();
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.InsertAtEnd(78);
  MyDblLinkedList.InsertAtBegining(385);
  MyDblLinkedList.InsertAtBegining(138);
  
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  MyDblLinkedList.DeleteLastNode();
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();
  
  cout<<"\nDBL Size: "<<MyDblLinkedList.Size()<<endl;

  if (MyDblLinkedList.IsEmpty())
    cout<<"Yes, it is empty\n";
  else
    cout<<"No, It is not empty\n"<<endl;

  cout<<"\nDo Reverse:\n";
  MyDblLinkedList.Reverse();
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();
  
  cout<<"\nClearing the list: ";
  MyDblLinkedList.Clear();

  cout<<"\nDBL Size: "<<MyDblLinkedList.Size()<<endl;
  MyDblLinkedList.PrintList();
  MyDblLinkedList.PrintListBackwards();

  return (0);
}
