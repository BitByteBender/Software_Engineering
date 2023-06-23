#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short Number1{0}, Number2{0}, Number3{0};
  std::string Prompt{"Enter Number "};
  cout<<Prompt<<"1: ";
  cin>>Number1;

  cout<<Prompt<<"2: ";
  cin>>Number2;

  cout<<Prompt<<"3: ";
  cin>>Number3;

  short Sum = Number1 + Number2 + Number3;
  cout<<"Total= "<<Sum<<endl;
  
  return 0;
}
