#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short Grades[4] = {0, 0, 0, 0};

  cout<<"Enter 1st grade: ";
  cin>>Grades[0];

  cout<<"Enter 2nd grade: ";
  cin>>Grades[1];

  cout<<"Enter 3rd grade: ";
  cin>>Grades[2];

  cout<<"Enter 4th grade: ";
  cin>>Grades[3];

  cout<<"1st Grade at index 0: "<<Grades[0]<<"\n";
  cout<<"2nd Grade  at index 1: "<<Grades[1]<<"\n";
  cout<<"3rd Grade  at index 2: "<<Grades[2]<<"\n";
  cout<<"4th Grade  at index 3: "<<Grades[3]<<"\n";

  float AvgGrades = (Grades[0] + Grades[1] + Grades[2] + Grades[3]) / 4.0f;

  cout<<"Average Grades: "<<AvgGrades<<endl;
  return 0;
}
