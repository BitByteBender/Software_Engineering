#include <iostream>

using std::cout;
using std::cin;
using std::endl;

uint16_t *ReadPositiveNumber(const char *Message)
{
  uint16_t *ptrNum = (uint16_t *)malloc(sizeof(uint16_t));

  cout<<Message;
  cin>>*ptrNum;

  return (ptrNum);
}

uint16_t FillArray(uint16_t *&Arr, uint16_t Length, uint16_t &LoopCount)
{
  uint16_t i = 0, UpdateLoop = 0;
  Arr = (uint16_t *)malloc(sizeof(uint16_t) * Length);

  do {
    Arr[i] = *ReadPositiveNumber("Enter a number to store in array: ");
    UpdateLoop = *ReadPositiveNumber("Do you want to add more? [0]:No | [1]:Yes\n");;
    i++;
    LoopCount++;
  } while (UpdateLoop == 1 && i < Length);

  return (*Arr);
}

void Print(const uint16_t *Arr, uint16_t LoopCount)
{
  uint16_t i = 0;

  cout<<"Array Length: "<<LoopCount<<"\n";
  cout<<"Array Elements: ";
  for (i = 0; i <= (LoopCount - 1) ; i++) {
    if (i != (LoopCount - 1)) {
      cout<<Arr[i]<<" ";
    }
    else {
      cout<<Arr[i];
    }
  }

  cout<<endl;
}

int main(void)
{
  uint16_t *Length = nullptr;
  uint16_t *Arr = nullptr;
  uint16_t LoopCount = 0;
  
  Length = ReadPositiveNumber("Enter max length: ");

  FillArray(Arr, *Length, LoopCount);
  Print(Arr, LoopCount);

  for (uint16_t i = 0; i < LoopCount; ++i) {
    free(&Arr[i]);
  }

  free(Arr);
  free(Length);
  return (0);
}
