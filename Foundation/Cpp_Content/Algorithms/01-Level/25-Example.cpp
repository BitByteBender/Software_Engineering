#include <iostream>
#include <string.h>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

uint16_t *ReadPositiveNumber(const char *);

uint16_t GenerateRandomNums(uint16_t, uint16_t);

char *_StringCopy(const char *);

void FillArray(uint16_t *&, uint16_t *);

uint16_t SumAllArrayElements(uint16_t *, uint16_t);

void PrintArrayElementsAndSum(uint16_t *, uint16_t, uint16_t);

int main(void)
{
  srand((unsigned)time(NULL));

  const char *Message = "Enter a number: ";
  char *NewMessage = _StringCopy(Message);
  
  uint16_t *Length = (uint16_t*)ReadPositiveNumber(NewMessage);
  uint16_t *Array = nullptr;

  FillArray(Array, Length);
  uint16_t Sum = SumAllArrayElements(Array, *Length);
  PrintArrayElementsAndSum(Array, *Length, Sum);

  free(NewMessage);
  free(Length);
  free(Array);
  return (0);
}


uint16_t *ReadPositiveNumber(const char *Message)
{
  uint16_t *ptrNum = (uint16_t*)malloc(sizeof(uint16_t));

  do {
    cout<<Message;
    cin>>*ptrNum;
    
  } while (*ptrNum <= 0);

  return (ptrNum);
}

uint16_t GenerateRandomNums(uint16_t Start, uint16_t End)
{
  uint16_t RandNum = (rand() % (End - Start + 1) + Start);
  return (RandNum);
}

char *_StringCopy(const char *Source)
{
  uint16_t i = 0, Length = strlen(Source);

  char *Destination = (char*)malloc(Length + 1);
  
  for (; i <= (Length - 1); i++) {
    Destination[i] = Source[i];
  }

  Destination[Length] = '\0';
  
  return (Destination);
}

void FillArray(uint16_t *&Array, uint16_t *Length)
{

  uint16_t i = 0;

  Array = (uint16_t*)malloc(sizeof(uint16_t) * (*Length + 1));
  
  for (i = 0; i <= (*Length - 1); i++) {
    Array[i] = GenerateRandomNums(1, 200);
  }

  Array[*Length] = '\0';
}

uint16_t SumAllArrayElements(uint16_t *Array, uint16_t Length)
{
  uint16_t i = 0, Sum = 0;

  for (; i <= (Length - 1); i++) {
    Sum += Array[i]; 
  }

  return (Sum);
}

void PrintArrayElementsAndSum(uint16_t *Array, uint16_t Length, uint16_t Sum)
{
  cout<<"Array elements: ";
  
  uint16_t i = 0;

  for (i = 0; i <= (Length - 1); i++) {
    if (i < (Length - 1)) {
      cout<<Array[i]<<' ';
    }
    else {
      cout<<Array[i]<<'\n';
    }
  }
  cout<<"Sum of all array elements is: "<<Sum<<endl;
}
