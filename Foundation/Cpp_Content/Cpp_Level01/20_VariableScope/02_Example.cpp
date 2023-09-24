#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;


short Number1;

short ReadNumber(string Message){
  short Num{0};

  cout<<Message;
  cin>>Num;

  return Num;
}

short Number = ReadNumber("Enter the 1st global number: ");

short CalculateNumbers(short Number){
  return (Number * 2);
}

void PrintTotal(short Total){
  cout<<"Total is: "<<Total<<endl;
}

int main()
{
  short Number = ReadNumber("Enter a local number: ");
  ::Number1 = ReadNumber("Enter the 2nd global number: ");

  PrintTotal(CalculateNumbers(Number));
  PrintTotal(CalculateNumbers(::Number));
  PrintTotal(CalculateNumbers(::Number1));
  return 0;
}

