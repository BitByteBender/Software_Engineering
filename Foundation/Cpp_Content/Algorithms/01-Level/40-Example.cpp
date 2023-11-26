#include <iostream>

using std::cout;
using std::cin;
using std::endl;

uint16_t *ReadPositiveNumber(const char *Message)
{
  uint16_t *ptrNum{(uint16_t *)malloc(sizeof(uint16_t))};

  do {
    cout<<Message;
    cin>>*ptrNum;
  } while (*ptrNum <= 0);

  return (ptrNum);
}

void FillArray(uint16_t *&Arr, uint16_t *Length)
{
  uint16_t i = 0;
  Arr = (uint16_t *)malloc(sizeof(uint16_t) + 1);

  for (i = 0; i <= (*Length - 1); i++) {
    Arr[i] = *ReadPositiveNumber("Value-> ");;
  }
}

void DisplayArray(const uint16_t *Arr, const uint16_t *Length)
{
  uint16_t i = 0;
  cout<<"Array elements: ";

  for (i = 0; i <= (*Length - 1); i++) {
    if (i < (*Length - 1)) {
      cout<<Arr[i]<<" ";
    }
    else {
      cout<<Arr[i]<<endl;
    }
  }
}
int main(void)
{
  uint16_t *Length = nullptr;
  uint16_t *Arr = nullptr;

  Length = ReadPositiveNumber("Enter the length array: ");

  FillArray(Arr, Length);
  DisplayArray(Arr, Length);
  
  return 0;
}

