#include "Header/DS/clsMyStack.hpp"

int main(void)
{
  clsMyStack<int> MyStack;
  
  MyStack.push(10);
  MyStack.push(50);
  MyStack.push(100);
  MyStack.push(150);
  MyStack.push(200);
  MyStack.push(250);

  cout<<"Stack: ";
  MyStack.Print();
  
  cout<<"Stack Size: "<<MyStack.Size()<<'\n';
  cout<<"Stack Top: "<<MyStack.Top()<<'\n';
  cout<<"Stack Bottom: "<<MyStack.Bottom()<<'\n';

  MyStack.pop();
  cout<<"\n>> An Item from the stack just popped!\n"<<endl;
  
  cout<<"Stack After<POP> (LIFO Operation):\n";
  MyStack.Print();
  
  cout<<"Stack Size: "<<MyStack.Size()<<'\n';
  cout<<"Stack Top: "<<MyStack.Top()<<'\n';
  cout<<"Stack Bottom: "<<MyStack.Bottom()<<'\n';

  cout<<"\n[Extension]>:"<<endl;
  MyStack.Reverse();
  cout<<"Stack After Reverse: ";
  MyStack.Print();

  cout<<"Item(2): "<<MyStack.GetItem(2)<<'\n';
  
  MyStack.UpdateItem(2, 500);
  cout<<"Stack after updating Item(2) to 500: \n";
  MyStack.Print();
  
  MyStack.InsertAfter(2, 900);
  cout<<"\nStack After inserting 900 after Item(2): \n";
  MyStack.Print();

  MyStack.InsertAtTop(2500);
  cout<<"\nStack after inserting 2500 at top: \n";
  MyStack.Print();

  MyStack.InsertAtBottom(3000);
  cout<<"\nStack after inserting 3000 at bottom: \n";
  MyStack.Print();

  MyStack.Clear();
  cout<<"\nStack after clearing: \n";
  MyStack.Print();
    
  return (0);
}
