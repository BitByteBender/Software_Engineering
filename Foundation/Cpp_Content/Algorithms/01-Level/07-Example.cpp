#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int *ReadPositiveNumber(string Message)
{
  int Num{0}, *ptrNum = &Num;

  cout<<Message;
  cin>>*ptrNum;

  return (ptrNum);
}

int CalcFrequency(int Num, unsigned short Digit)
{
  unsigned short Remainder{0}, Frequency{0};

  while (Num > 0) {
    Remainder = Num % 10;
    Num = Num / 10;

      if (Remainder == Digit) {
	Frequency = Frequency + 1;
      }
  }

  return (Frequency);
}

void PrintFrequency(unsigned short Digit, unsigned short Frequency)
{
  if (Frequency > 2) {
      cout<<"Digit "<<Digit<<" frequency repeated "<<Frequency<<" times.\n";
  }
  else
  {
    cout<<"Digit "<<Digit<<" frequency repeated "<<Frequency<<" time.\n";
  }
}

int main()
{
  int Num = *ReadPositiveNumber("Enter a number to check: ");
  short Digit = *ReadPositiveNumber("Enter a digit: ");
  PrintFrequency(Digit, CalcFrequency(Num, Digit));
  
  return 0;
}
