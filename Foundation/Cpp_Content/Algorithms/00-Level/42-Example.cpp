#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadNumber(string Message)
{
  short Num{0};

  cout<<Message;
  cin>>Num;
  
  return Num;
}

void ReadGrade(unsigned short &Grade)
{
  Grade = ReadNumber("Enter grade: ");
}

string CheckGrades(unsigned short Grade)
{
  if (Grade >= 90 || Grade == 100) {
    return "A";
  }
  else if(Grade >= 80)
  {
    return "B";
  }
  else if(Grade >= 70)
  {
    return "C";
  }
  else if (Grade >= 60)
  {
    return "D";
  }
  else if (Grade >= 50)
  {
    return "E";
  }
  else
  {
    return "F";
  }
}

void PrintGrade(string GradeResult)
{
  cout<<"Grade: "<<GradeResult<<endl;
}

int main()
{
  unsigned short Grade{0};

  ReadGrade(Grade);
  PrintGrade(CheckGrades(Grade));
  return 0;
}
