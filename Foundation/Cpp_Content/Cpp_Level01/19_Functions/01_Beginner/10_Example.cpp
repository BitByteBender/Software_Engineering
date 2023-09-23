#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void MySumProcedure(){
  short Number1{0}, Number2{0};
  
  cout<<"Enter number1?: ";
  cin>>Number1;

  cout<<"Enter Number2?: ";
  cin>>Number2;

  cout<<"\n**********************\n";
  
  short Result = Number1 + Number2;

  cout<<Result<<endl;
}
  
int main()
{
  MySumProcedure();
  
  return 0;
}
