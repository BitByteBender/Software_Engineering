#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

uint16_t *ReadNumber(const char *Message)
{
  uint16_t *PtrNumber = (uint16_t *)new uint16_t(sizeof(uint16_t));

  cout<<Message;
  cin>>*PtrNumber;

  return (PtrNumber);
}

uint16_t Randomizer(uint16_t Start, uint16_t End)
{
  uint16_t RandNum = (rand() % (End - Start + 1) + Start);
  return (RandNum);
}

void ArrayFiller(uint16_t *&Arr, uint16_t *&Length)
{
  Length = ReadNumber("How many elements? ");
  Arr = (uint16_t *)new uint16_t[*Length + 1];
  
  uint16_t i = 0;
  
  for (i = 0; i <= (*Length - 1); i++) {
    Arr[i] = Randomizer(1, 100);
  }

   Arr[*Length] = '\0';
}

uint16_t CalcSum(uint16_t *Arr, uint16_t Length)
{
  uint16_t i = 0, Sum = 0;

  for (i = 0; i <= (Length - 1); i++) {
    Sum += Arr[i];
  }

  return (Sum);
}

inline float CalcAvg(uint16_t Length, uint16_t Sum)
{
  return ((float)Sum / Length);
}

void PrintArrayElements(uint16_t *Arr, uint16_t Length)
{
  uint16_t i = 0;

  cout<<"Array Elements: ";
  
  for (i = 0; i <= (Length - 1); i++) {
    if (i < (Length - 1))
    {
      cout<<Arr[i]<<' '; 
    }
    else
    {
      cout<<Arr[i]<<'\n';
    }
  }
}

void PrintSumAndAverage(uint16_t Sum, float Avg)
{
  cout<<"Sum of all elements: "<<Sum<<'\n';
  cout<<"Average of all elements: "<<Avg<<endl;
}

int main()
{
  srand((unsigned)time(NULL));
  
  uint16_t *Length = nullptr;
  uint16_t *Arr = nullptr;
  uint16_t Sum{0};
  float Avg{0.0f};

  ArrayFiller(Arr, Length);
  Sum = CalcSum(Arr, *Length);
  Avg = CalcAvg(*Length, Sum);

  PrintArrayElements(Arr, *Length);
  PrintSumAndAverage(Sum, Avg);

  delete Length;
  delete[] Arr;
  return (0);
}
