#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

short ReadNumber(string Message)
{
  short Number{0};

  cout<<Message;
  cin>>Number;
  
  return Number;
}

float HalfNumber(short Number)
{
  return (float)Number / 2.0f;
}

void PrintHalfNumber(float Number)
{
  cout<<"Half of "<<Number<<" is "<<HalfNumber(Number)<<endl;
}

int main()
{
  short Number = ReadNumber("Enter a number: ");
  PrintHalfNumber(Number);
  return 0;
}
