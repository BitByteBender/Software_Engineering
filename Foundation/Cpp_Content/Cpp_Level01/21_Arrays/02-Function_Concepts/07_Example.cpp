#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ReadGrades(short Grades[3]){

  cout<<"Enter the 1st grade: ";
  cin>>Grades[0];

  cout<<"Enter the 2nd grade: ";
  cin>>Grades[1];

  cout<<"Enter the 3rd grade: ";
  cin>>Grades[2];

}

float AverageGrades(short Grades[3]){
  return (Grades[0] + Grades[1] + Grades[2]) / 3.0f;
}

int main()
{
  short Grades[3] = {0, 0, 0};
  ReadGrades(Grades);
  cout<<"The average of grades is: "<<AverageGrades(Grades)<<endl;
  return 0;
}
