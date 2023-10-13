#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

void ReadArrayGrades(float Arr[20], unsigned short &Length)
{
  cout<<"How many grades?: ";
  cin>>Length;

  unsigned short i{0};
  do {
    cout<<"Enter Grade"<<i+1<<" :\n";
    cin>>Arr[i];
    i++;
  } while (Length > i);
}

void DisplayArrayGrades(float Arr[20], unsigned short Length)
{
  unsigned short i;
  for (i = 0; i < Length; i++)
  {
    cout<<"Grade ["<<i+1<<"]: "<<Arr[i]<<"\n";
  }
}

float CalculateSumOfGrades(float Arr[20], unsigned short Length)
{
  float Sum = 0.0f;
  unsigned short i;

  for (i = 0; i < Length; i++) {
    Sum = Sum + Arr[i];
  }

  return Sum;
}

float CalculateAverageOfGrade(float Arr[20], unsigned short Length)
{
  return CalculateSumOfGrades(Arr, Length) / Length;
}

int main()
{
  float Arr[20];
  unsigned short Length{0};

  ReadArrayGrades(Arr, Length);
  DisplayArrayGrades(Arr, Length);

  cout<<"Sum: "<<CalculateSumOfGrades(Arr, Length)<<"\n"
      <<"Average: "<<CalculateAverageOfGrade(Arr, Length)<<endl;
  
  return 0;
}
