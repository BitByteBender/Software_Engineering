#include <iostream>
#include <string.h>
#include <cstdint>

using std::cout, std::endl;
using std::cin;
using std::string, std::to_string;

short *ReadPositiveNumber(string);
void PrintInvertedPattern(short, uint16_t);

int main()
{
  short *Number = ReadPositiveNumber("Enter a number: ");

  PrintInvertedPattern(*Number, *Number);
  
  delete (Number);

  return (0);
}

short *ReadPositiveNumber(string Message)
{
  short *ptrNumber = new short;

  do {
    cout<<Message;
    cin>>*ptrNumber;
  } while (*ptrNumber <= 0);

  return (ptrNumber);
}

void PrintInvertedPattern(short Digit, uint16_t Counter = 0)
{
  uint16_t j;

  if (Counter > 0)
  {
      for (j = 0; j < Counter; j++)
      {
	cout<<Counter;
      }
      putchar('\n');
      PrintInvertedPattern(Digit, Counter - 1);
  }
}
