#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  short Num{0};

  cout<<"Please enter a number: ";
  cin>>Num;

  cout<<Num * Num<<"\n";
  cout<<Num * Num * Num<<"\n";
  cout<<Num * Num * Num * Num<<endl;
  return 0;
}
