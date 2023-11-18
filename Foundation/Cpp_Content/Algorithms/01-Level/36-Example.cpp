#include <iostream>
#include <ctime>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

uint16_t ReadPositiveNumber(string Message)
{
  uint16_t Num = 0;

  cout<<Message;
  cin>>Num;

  return (Num);
}

uint16_t Randomizer(uint16_t From, uint16_t To)
{
  uint16_t Random = (rand() % (To - From + 1)) + From;
  return (Random);
}

void FillArray(uint16_t Arr[100], uint16_t Length)
{
  uint16_t i = 0;

  for (i = 0; i <= (Length - 1); i++) {
    Arr[i] = Randomizer(1, 100);
  }
}

void PrintArrayElements(uint16_t Arr[100], uint16_t Length, char Msg)
{
  uint16_t i = 0;
  
  cout<<"Array "<<Msg<<" elements: ";

  for (i = 0; i <= (Length - 1); i++) {
    if (i < (Length - 1)) {
      cout<<Arr[i]<<" ";
    }
    else {
      cout<<Arr[i]<<endl;
    }
  }
}

void AddArrayElements(uint16_t Number, uint16_t Arr[100], uint16_t &Length)
{
  Length++;
  Arr[Length - 1] = Number;
}


void CopyArr(uint16_t Arr[100], uint16_t CopyArr[100], uint16_t ArrLength, uint16_t &CopyArrLength)
{
  uint16_t i = 0;
  
  for (i = 0; i <= (ArrLength - 1); i++) {
    AddArrayElements(Arr[i], CopyArr, CopyArrLength);
  }
}

int main()
{
  srand((unsigned)time(nullptr));

  uint16_t Number = 0;
  uint16_t Length = 0;
  uint16_t Arr[100];

  
  Length = ReadPositiveNumber("How many elements: ");
  
  FillArray(Arr, Length);
  uint16_t  CopiedArr[100];
  CopyArr(Arr, CopiedArr, Length, Number);

  PrintArrayElements(Arr, Length, '1');
  PrintArrayElements(CopiedArr, Number, '2');
  
  return 0;
}
