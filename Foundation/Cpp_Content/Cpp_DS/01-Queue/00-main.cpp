#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::string;
using std::queue;

int main(void)
{
  queue <string> Str;
  queue <string> Str2;
  queue <string> Str3;
  
  Str.push("This");
  Str.push("is");
  Str.push("the");
  Str.push("queue");
  Str.push("DS!");

  cout<<"Queue[Str] (FIFO): ";
  while (!Str.empty()) {
    cout<<Str.front()<<' ';

    Str2.push(Str.front());
    Str.pop();
  }
  cout<<endl;


  cout<<"Queue[Str2] Back: "<<Str2.back()<<endl;

  Str2.swap(Str3);
  cout<<"Queue[Str3] Front: "<<Str3.front()<<endl;
  
  cout<<"Queue[Str3] (FIFO): ";
  while (!Str3.empty()) {
    cout<<Str3.back()<<' ';
    Str3.pop();
  }
  cout<<endl;
  return (0);
}
