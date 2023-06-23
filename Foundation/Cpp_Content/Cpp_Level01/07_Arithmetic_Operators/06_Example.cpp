#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  short Number1{0}, Number2{0};
  
  cout<<"Enter Number 1: ";
  cin>>Number1;

  cout<<"Enter Number 2: ";
  cin>>Number2;

  cout<<"Before Swapping: \n";
  cout<<Number1<<"\n"<<Number2<<"\n";

  //Bucket switch method
  short Temp = Number1;
  Number1 = Number2;
  Number2 = Temp;

  cout<<"After Swapping: \n";
  cout<<Number1<<"\n"<<Number2<<endl;
  return 0;
}
