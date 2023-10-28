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

void PrintInvertedLetter(uint16_t Digit, uint32_t n)
{
  uint32_t j;
  
  if (n >= 65) {
    for (j = n; j >= 65; j--) {
      putchar(n);
    };
    putchar('\n');
    PrintInvertedLetter(Digit, (n - 1));
  }
}


int main()
{
  short *Number = ReadPositiveNumber("Enter a number: ");
  PrintInvertedLetter(*Number, (*Number + 64));
  
  delete (Number);

  return (0);
}
