#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ReadArrayData(int Arr[10], int &Length)
{
  cout<<"Enter How many numbers: ";
  cin>>Length;
  
  short i = 1;
  
  do {
    
    cout<<"Enter num"<<i<<"\n";
    cin>>Arr[i];
    i++;
  } while (i <= Length);
}

void PrintArrayData(int Arr[10], int Length)
{
  for (short i = 1; i <= Length; i++)
  {
    cout<<"Number ["<<i<<"] : "<<Arr[i]<<"\n";
  }
}

int CalculateArraySum(int Arr[10], int Length)
{
  int Sum = 0;

  for (int i = 0; i <= Length; i++) {
    Sum = Sum + Arr[i];
  }
  return Sum;
}

float CalculateArrayAverage(int Arr[10], int Length)
{
  float Avg = CalculateArraySum(Arr, Length) / Length;
  return Avg;
}

int main()
{
  int Arr[10], Length{0};
  ReadArrayData(Arr, Length);
  PrintArrayData(Arr, Length);
  cout<<"Sum: "<<CalculateArraySum(Arr, Length)<<"\n";
  cout<<"Average: "<<CalculateArrayAverage(Arr, Length)<<endl;
  return 0;
}
