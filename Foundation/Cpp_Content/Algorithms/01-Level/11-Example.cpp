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

short PrintInvertedPattern(short Digit)
{
  uint32_t i = Digit, j = i;
  
  if (i == 1 || Digit == 1) {
    return (1);
  }
  else
  {
    for (i = Digit; i >= 1; i--) {
      for (j = 0; j < i; j++) {
	cout<< i;
      }
      cout<<endl;
    }
  }
  return (EXIT_SUCCESS);
}

int main()
{
  short *Number = ReadPositiveNumber("Enter a number: ");
  
  PrintInvertedPattern(*Number);
  
  delete (Number);

  return (0);
}
