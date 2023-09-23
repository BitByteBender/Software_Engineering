#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

void ReadNumbers(string Message, short& Number, short& Exponent){

  cout<<Message;
  cin>>Number;

  cout<<Message;
  cin>>Exponent;
}

short CalculatePower(short& Number, short& Exponent){
  return pow(Number, Exponent);
}

void PrintResult(string Message, short Result){
  cout<<Message<<Result<<endl;
}

int main()
{
  short Number = 0, Exponent = 0;
  ReadNumbers("Enter a number: ", Number, Exponent);
  PrintResult("The Result is: ", CalculatePower(Number, Exponent));
  return 0;
}
