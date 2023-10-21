#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct stMarks
{
  unsigned short Mark1, Mark2, Mark3;
};

short ReadNumber(std::string Message)
{
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

void ReadMarks(stMarks &Marks)
{
  Marks.Mark1 = ReadNumber("Enter mark1: ");
  Marks.Mark2 = ReadNumber("Enter mark2: ");
  Marks.Mark3 = ReadNumber("Enter mark3: ");
}

short SumOfMarks(stMarks Marks)
{
  short Sum = 0;
  return Sum = (Marks.Mark1 + Marks.Mark2 + Marks.Mark3);
}

float AverageMarks(stMarks Marks)
{
  return SumOfMarks(Marks) / 3.0f;
}
void PrintAverage(stMarks Marks)
{
  cout<<"Average: "<<AverageMarks(Marks)<<endl;
}

int main()
{
  stMarks Marks;
  ReadMarks(Marks);
  PrintAverage(Marks);
  return 0;
}
