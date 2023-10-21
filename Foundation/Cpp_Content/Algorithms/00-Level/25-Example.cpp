#include <iostream>
#include "cmath"

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadNumbers(string Message)
{
  short Number{0};
  
  cout<<Message;
  cin>>Number;

  return Number;
}

float CalculateArea(short Height, short Diagonal)
{
  return ((float)Height * sqrt(pow(Diagonal, 2) - pow(Height, 2)));
}

void PrintArea(short Height, short Diagonal)
{
  cout<<"Rectangle Area Through Diagonal and Side Area: "<<CalculateArea(Height, Diagonal)<<endl;
}

int main()
{
  short Height{0}, Diagonal{0};

  Height = ReadNumbers("Enter Height: ");
  Diagonal = ReadNumbers("Enter Diagonal: ");
  PrintArea(Height, Diagonal);
  return 0;
}
