#include <iostream>

using std::cout;
using std::cin;
using std::endl;

short ReadNumbers(std::string MessageHolder){

  short Number{0};

  cout<<MessageHolder;
  cin>>Number;

  return Number;
}

short MySumFunction(short FirstNumber, short SecondNumber){
  short Sum = FirstNumber + SecondNumber;
  return Sum;
}

void PrintSum(){
  short FirstNumber = ReadNumbers("Enter the 1st number: ");
  short SecondNumber = ReadNumbers("Enter the 2nd number: ");

  cout<<"The Sum is: "<<MySumFunction(FirstNumber, SecondNumber)<<endl;
}

int main()
{
  PrintSum();
  return 0;
}
