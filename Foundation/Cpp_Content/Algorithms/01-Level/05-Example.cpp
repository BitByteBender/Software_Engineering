#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadPositiveNumber(string Message)
{
  short Number{0};

  do {
    cout<<Message;
    cin>>Number;
  } while (Number<=0);
  
  return (Number);
}

short IsolatedNumbers(short Num)
{
  short Remainder{0}, Sum{0};

  while (Num > 0) {
    Remainder = Num % 10;
    Num = Num / 10;
    Sum = Sum + Remainder;
  }

  return (Sum);
}

void PrintSumOfDigits(short Sum)
{
  cout<<"Sum of digits: "<<Sum<<endl;
}

int main()
{
  short Num = ReadPositiveNumber("Enter a number: ");
  PrintSumOfDigits(IsolatedNumbers(Num));
  return 0;
}
