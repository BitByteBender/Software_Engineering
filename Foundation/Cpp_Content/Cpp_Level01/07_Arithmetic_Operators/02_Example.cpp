#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  int Num1{0}, Num2{0};
  
  cout<<"Enter a number of your choice: ";
  cin>>Num1;

  cout<<"Enter a second number of your choice: ";
  cin>>Num2;

  //Outputs
  cout<<Num1<<" + "<< Num2<<" = "<<Num1+Num2<<"\n";
  cout<<Num1<<" - "<<Num2<<" = "<<Num1-Num2<<"\n";
  cout<<Num1<<" * "<<Num2<<" = "<<Num1*Num2<<"\n";
  cout<<Num1<<" / "<<Num2<<" = "<<Num1/Num2<<"\n";
  cout<<Num1<<" % "<<Num2<<" = "<<Num1%Num2<<"\n";
  return 0;
}
