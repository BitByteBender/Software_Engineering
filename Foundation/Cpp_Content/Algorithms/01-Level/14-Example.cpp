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

void PrintLetters(uint16_t Digit)
{
  uint16_t i = 0, j;
  
    for (i = 65; i < (Digit + 65); i++) {
      for (j = 65; j <= i; j++) {
	cout<<char(i);
      }
      cout<<"\n";
    }

}


int main()
{
  short *Number = ReadPositiveNumber("Enter a number: ");
  PrintLetters(*Number);
  
  delete (Number);

  return (0);
}
