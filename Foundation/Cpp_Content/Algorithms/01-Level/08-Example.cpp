#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int ReadPositiveNumber(string Message)
{
  int Num{0};
  int *ptrNum = &Num;
  
  cout<<Message;
  cin>>*ptrNum;

  return (*ptrNum);
}

int CountDigitFrequency(int Num, short Digit)
{
  short Remainder{0}, Frequency{0};

  while (Num > 0) {
    Remainder = Num % 10;
    Num = Num / 10;

    if (Remainder == Digit) {
      Frequency ++;
    }
  }
  
  return (Frequency);
}

void PrintAllDigitFrequency(int Num)
{
  short i = 0;
  
  while (i < 10) {
    if (CountDigitFrequency(Num, i) > 0) {
      cout<<"Digit "<<i<<" Frequency is "<<CountDigitFrequency(Num, i)<<" time.\n";
    }
    i++;
  }
}

int main()
{
  int Num = ReadPositiveNumber("Enter a number: ");

  PrintAllDigitFrequency(Num);
  return 0;
}

