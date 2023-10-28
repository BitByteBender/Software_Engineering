#include <iostream>

using std::cout, std::endl;
using std::cin;
using std::string;

short *ReadPositiveNumber(string Message)
{
  short *ptrNumber = new short;

  do {
    cout<<Message;
    cin>>*ptrNumber;
  } while (*ptrNumber <= 0);

  return (ptrNumber);
}

void PrintInvertedPattern(uint16_t Digit, uint16_t i)
{
  uint16_t j;
  
  if (i > 0 && i <= Digit) {
    for (j = 1; j <= i; j++) {
      cout<<i;
    };
    putchar('\n');
    PrintInvertedPattern(Digit, (i + 1));
  }
}


int main()
{
  short *Number = ReadPositiveNumber("Enter a number: ");
  
  PrintInvertedPattern(*Number, 1);
  
  delete (Number);

  return (0);
}
