#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

uint16_t *ReadPositiveNumber(const char *Message)
{
  uint16_t *ptrNum = (uint16_t *)new uint16_t;

  cout<<Message;
  cin>>*ptrNum;

  return (ptrNum);
}

uint16_t RandomNumber(uint16_t From, uint16_t To)
{
  uint16_t RandNumber = (rand() % (To - From + 1) + From);
  return (RandNumber);
}

void FillArray(uint16_t *Arr[], uint16_t Length)
{
  uint16_t i = 0;
  
  //*Arr = new uint16_t[Length + 1];

  for (i = 0; i <= (Length - 1); i++) {
    (*Arr)[i] = RandomNumber(1, 100);
  }
}

uint16_t *CopyArray(uint16_t *Arr, uint16_t Length)
{
  uint16_t i = 0, *CopiedArr = new uint16_t[Length + 1];
  
  for (i = 0; i <= (Length - 1); i++) {
    CopiedArr[i] = Arr[i];
  }

  return (CopiedArr);
}

void PrintArrayElements(const uint16_t *Arr, const uint16_t *CopiedArr, uint16_t Length)
{
  cout<<"Array 1 elements: ";

  uint16_t i = 0;

  for (i = 0; i <= (Length - 1); i++) {
    cout<<Arr[i]<<" ";
  }
  cout<<endl;
  cout<<"Array 2 elements: ";
  
  for (i = 0; i <= (Length - 1); i++) {
    cout<<CopiedArr[i]<<" ";
  }
  cout<<endl;

 
}

int main()
{
  srand((unsigned)time(NULL));
  
  uint16_t *Length = ReadPositiveNumber("Enter array elements: ");
  uint16_t *Arr = new uint16_t[*Length];
  uint16_t *CopiedArr = nullptr;
  
  FillArray(&Arr, *Length);
  CopiedArr = CopyArray(Arr, *Length);  
  PrintArrayElements(Arr, CopiedArr, *Length);
  
  delete Length;
  delete[] Arr;
  delete[] CopiedArr;
  return 0;
}
