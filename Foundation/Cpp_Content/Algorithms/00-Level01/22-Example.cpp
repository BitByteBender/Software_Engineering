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

float CheckMaxNumber(float Num1, float Num2, float Num3)
{
  if (Num1 > Num2) {
    if (Num1 > Num3) {
      return Num1;
    }
    else
    {
      return Num3;
    }
  }
  else
  {
    if (Num2 > Num3) {
      return Num2;
    }
    else
    {
      return Num3;
    }
  }
}

void PrintMaxNumber(float Num1, float Num2, float Num3)
{
  cout<<CheckMaxNumber(Num1, Num2, Num3)<<endl;
}

int main()
{
  float Num1{0}, Num2{0}, Num3{0};

  Num1 = ReadNumber("Enter num1: ");
  Num2 = ReadNumber("Enter num2: ");
  Num3 = ReadNumber("Enter num3: ");
  
  PrintMaxNumber(Num1, Num2, Num3);
  return 0;
}
