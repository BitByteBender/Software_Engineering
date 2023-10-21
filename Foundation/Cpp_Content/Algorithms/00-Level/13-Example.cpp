#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main()
{
  short From{18}, To{45}, Number;
  cout<<"Enter a number: ";
  cin>>Number;

  while (Number < From || Number > To)
  {
    cout<<"Wrong number.\n";
    cout<<"Enter another number: ";
    cin>>Number;
  }

  cout<<Number<<endl;
  
  return 0;
}
