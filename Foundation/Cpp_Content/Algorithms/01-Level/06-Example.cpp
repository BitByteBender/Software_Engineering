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

unsigned short ReverseNumber(short Num)
{
  short Remainder{0};
  unsigned short inReverse{0};

  while (Num > 0) {
    Remainder = Num % 10;
    Num = Num / 10;
    inReverse = (inReverse + Remainder) * 10;
  }

  return (inReverse / 10);
}

void PrintSumOfDigits(unsigned short RevNumber)
{
  cout<<"Number in reverse: "<<RevNumber<<endl;
}

int main()
{
  short Num = ReadPositiveNumber("Enter a number: ");
  PrintSumOfDigits(ReverseNumber(Num));
  return 0;
}
