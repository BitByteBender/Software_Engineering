#include <iostream>

using std::cout;
using std::endl;
using std::string;

//Procedure
void MyProcedure(){

  cout<<"This my Procedure.\n";
}

//Function
string MyFunction1(){
  return "This my 1st function.\n";
}

int MyFunction2(){

  int X{25}, Y{10};

  return (X * Y) - (Y * 5);
}

int main()
{
  MyProcedure();

  cout<<MyFunction1();

  int Result = MyFunction2();
  cout<<Result<<endl;
  return 0;
}
