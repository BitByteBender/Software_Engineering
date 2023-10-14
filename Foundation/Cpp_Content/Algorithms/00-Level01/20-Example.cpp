#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

short ReadNumber(string Message)
{
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

void ReadMarks(float &Mark1, float &Mark2, float &Mark3)
{
  Mark1 = ReadNumber("Enter Mark1: ");
  Mark2 = ReadNumber("Enter Mark2: ");
  Mark3 = ReadNumber("Enter Mark3: ");
}

float CalculateAverage(float Mark1, float Mark2, float Mark3)
{
  float Sum = 0;
  Sum = Mark1 + Mark2 + Mark3;
  return (Sum / 3.0f);
}

string PassOrFail(float Mark1, float Mark2, float Mark3)
{
  return (CalculateAverage(Mark1, Mark2, Mark3) >= 50 ? "Pass" : "Fail");
}

void PrintResult(float Avg, float Mark1, float Mark2, float Mark3)
{
  cout<<"Average: "<<Avg<<"\n"
      <<"Result: "<<PassOrFail(Mark1, Mark2, Mark3)<<endl;
}

int main()
{
  float Mark1{0}, Mark2{0}, Mark3{0}, Avg{0};
  
  ReadMarks(Mark1, Mark2, Mark3);
  Avg = CalculateAverage(Mark1, Mark2, Mark3);
  PrintResult(Avg, Mark1, Mark2, Mark3);
  return 0;
}

