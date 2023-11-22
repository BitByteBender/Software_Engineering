#include <iostream>
#include <ctime>

using std::cout;
using std::endl;


void PrintArrayElements(const unsigned short Arr[100], const unsigned short Length, const char *Message)
{
  unsigned short i = 0;
  
  cout<<Message;
  
  for (i = 0; i <= (Length - 1); i++) {
    if (i == (Length - 1)) {
      cout<<Arr[i];
    }
    else
    {
      cout<<Arr[i]<<" ";
    }
  }

  cout<<endl;
}

void AddArrayElements(unsigned short Number, unsigned short Arr[100], unsigned short &Length)
{
  Length++;
  Arr[Length - 1] = Number;
}

void CopyDistinctNumbers(unsigned short ArrSrc[100], unsigned short ArrDest[100], unsigned short SrcLength, unsigned short &DestLength)
{
  unsigned short i = 0, j = 0;

  for (i = 0; i <= (SrcLength - 1); i++) {
    for (j = 0; j <= i; j++) {
      if (ArrSrc[i] != ArrDest[j]) {
	if (i == j) {
	  AddArrayElements(ArrSrc[i], ArrDest, DestLength);
	}
        continue;
      }
      else {
	break;
      }
    }
  }
}

int main(void)
{
  unsigned short ArrSrc[10] = {10, 10, 20, 10, 50, 50, 70, 50, 70, 90}, ArrDest[10];
  unsigned short SrcLength = 10, DestLength = 0;
  PrintArrayElements(ArrSrc, SrcLength, "Array 1 elements:\n");
 
  CopyDistinctNumbers(ArrSrc, ArrDest, SrcLength, DestLength);
  PrintArrayElements(ArrDest, DestLength, "Array 2 distinct elements:\n");

  return (0);
}
