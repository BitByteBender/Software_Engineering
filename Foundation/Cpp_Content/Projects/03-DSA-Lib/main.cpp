#include "Header/DS/clsMyQueue.hpp"

int main(void)
{
  clsMyQueue<int> MyQueue;

  MyQueue.push(10);
  MyQueue.push(50);
  MyQueue.push(100);
  MyQueue.push(150);
  MyQueue.push(200);
  MyQueue.push(250);

  cout<<"Queue: ";
  MyQueue.Print();
  
  cout<<"Queue Size: "<<MyQueue.Size()<<'\n';
  cout<<"Queue Front: "<<MyQueue.front()<<'\n';
  cout<<"Queue Back: "<<MyQueue.back()<<'\n';

  MyQueue.pop();
  cout<<"\n>> An Item from the queue just popped!\n"<<endl;
  
  cout<<"Queue After<POP> (FIFO Operation):\n";
  MyQueue.Print();
  
  cout<<"Queue Size: "<<MyQueue.Size()<<'\n';
  cout<<"Queue Front: "<<MyQueue.front()<<'\n';
  cout<<"Queue Back: "<<MyQueue.back()<<'\n';

  cout<<"\n[Extension]>:"<<endl;
  MyQueue.Reverse();
  cout<<"Queue After Reverse: ";
  MyQueue.Print();

  cout<<"Item(2): "<<MyQueue.GetItem(2)<<'\n';
  
  MyQueue.UpdateItem(2, 500);
  cout<<"Queue after updating Item(2) to 500: \n";
  MyQueue.Print();
  
  MyQueue.InsertAfter(2, 900);
  cout<<"\nQueue After inserting 900 after Item(2): \n";
  MyQueue.Print();

  MyQueue.InsertAtFront(2500);
  cout<<"\nQueue after inserting 2500 at front: \n";
  MyQueue.Print();

  MyQueue.InsertAtBack(3000);
  cout<<"\nQueue after inserting 3000 at back: \n";
  MyQueue.Print();

  MyQueue.Clear();
  cout<<"\nQueue after clearing: \n";
  MyQueue.Print();
    
  return (0);
}
