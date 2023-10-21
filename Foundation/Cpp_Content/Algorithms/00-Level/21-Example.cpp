#include <iostream>

using std::cout;
using std::endl;
using std::cin;

short ReadNumber(std::string Message)
{
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

bool CheckMaxNumber(float Num1, float Num2)
{
  return (Num1 < Num2 ? 0 : 1);
}

void PrintMaxNumber(float Num1, float Num2)
{
  if (CheckMaxNumber(Num1, Num2))
  {
    cout<<Num1<<endl;
  }
  else
  {
    cout<<Num2<<endl;
  }
}

int main()
{
  float Num1{0}, Num2{0};

  Num1 = ReadNumber("Enter num1: ");
  Num2 = ReadNumber("Enter num2: ");

  PrintMaxNumber(Num1, Num2);
  return 0;
}
