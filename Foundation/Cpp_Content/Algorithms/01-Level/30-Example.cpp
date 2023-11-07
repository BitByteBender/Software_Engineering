#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

short *ReadPositiveNumber(const char *Message)
{
  short *ptrNum = (short *)malloc(sizeof(short));

  do {
    cout << Message;
    cin >> *ptrNum;
  } while (*ptrNum <= 0);

  return (ptrNum);
}

short NumberRandomizer(short From, short To)
{
  short Randomize = (rand() % (To - From + 1) + From);
  return (Randomize);
}

void FillArray(short *Arr[], short Length)
{
  short i = 0;
  
  for (i = 0; i < Length; i++) {
    Arr[i] = (short *)malloc(sizeof(short));
    *Arr[i] = (i + 1);
  }

  Arr[Length] = nullptr;

}

short *ShuffledArrArray(short *ShuffledArr[], const short Length)
{

  short i = 0, j = 0, RandNum = 0;
  
  for (i = 0; i < (Length); i++) {
    ShuffledArr[i] = (short *)malloc(sizeof(short));
    RandNum = NumberRandomizer(1, Length);

    if (i == 0) {
      *ShuffledArr[i] = RandNum;
    }
    else {
    for (j = 0; j < i; j++) {

      if (*ShuffledArr[j] == RandNum) {
	RandNum = NumberRandomizer(1, Length);
	j = -1;
      }
      else
      {
	continue;
      }
    }
    
    *ShuffledArr[i] = RandNum;
    continue;
    }
  }

  ShuffledArr[Length] = nullptr;
  
  return (*ShuffledArr);
}

void PrintArrayElements(const char *Text, short *Arr[], const short Length)
{
  cout << Text;

  for (short i = 0; i < Length; i++) {
    if (i == Length - 1) {
      cout << *Arr[i] << endl;
    } else {
      cout << *Arr[i] << ' ';
    }
  }
}

void FreeMemoAlloc(short *ptrNum, short *Arr[], short *ShuffledArr[])
{
  short i = 0;

  for (i = 0; i <= (*ptrNum - 1); i++) {
    free(Arr[i]);
    free(ShuffledArr[i]);
  }

  free(ptrNum);
}

int main(void)
{
  srand((unsigned)time(NULL));

  short *Length = ReadPositiveNumber("Enter the length of an array: ");
  short *Arr[*Length + 1], *ShuffledArr[*Length + 1];

  FillArray(Arr, *Length);
  PrintArrayElements("Array elements before shuffle: ", Arr, *Length);

  ShuffledArrArray(ShuffledArr, *Length);
  PrintArrayElements("Array elements after shuffle: ", ShuffledArr, *Length);

  FreeMemoAlloc(Length, Arr, ShuffledArr);
  return 0;
}
