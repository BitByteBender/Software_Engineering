#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

int main(void)
{
  stack <int16_t> Integers;
  
  // Filling a stack
  Integers.push(1);
  Integers.push(51);
  Integers.push(91);
  Integers.push(19);
  Integers.push(18);

  cout<<"Stack (LIFO): ";
  while (!Integers.empty()) {
    cout<<Integers.top()<<' ';
    Integers.pop();
  }
  cout<<endl;

  return (0);
}
