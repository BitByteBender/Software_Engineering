#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

unsigned short ReadNumber(string Message){
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

short CalculateExponentials(short Base, short Exponent){
  return pow(Base, Exponent);
}

void PrintResult(short Base, short Exponent, short Result){
  cout<<Base<<" To the power of "<<Exponent<<" = "<<Result<<endl;
}

int main()
{
  short Base = ReadNumber("Enter the base number: ");
  short Exponent = ReadNumber("Enter the Exponent number: ");
  PrintResult(Base, Exponent, CalculateExponentials(Base, Exponent));
  return 0;
}
