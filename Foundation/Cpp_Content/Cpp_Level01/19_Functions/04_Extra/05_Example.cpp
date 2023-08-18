#include <iostream>

using std::cout;
using std::endl;


void NumberSwapper(short Number1, short Number2){
  short TempVar = Number1;
  Number1 = Number2;
  Number2 = TempVar;
  //you shouldn't be printing the result inside this function(i just did it like this to showcase the many possible ways)
  cout<<"Number1 = "<<Number1<<" - Number2 = "<<Number2<<"\n";
}

void PrintSwappedNumbers(short Number1, short Number2){
   
  cout<<"Beore Swapping: Number1 = "<<Number1<<" - Number2 = "<<Number2<<"\n";
  cout<<"After Swapping: ";
  NumberSwapper(Number1, Number2);
  cout<<endl;
  
}

int main()
{
  short Number1{10}, Number2{20};
  PrintSwappedNumbers(Number1, Number2);
  return 0;
}
