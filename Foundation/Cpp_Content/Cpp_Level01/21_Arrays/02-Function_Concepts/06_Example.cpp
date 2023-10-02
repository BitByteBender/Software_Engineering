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

float AverageGrades(float &Avg, short Grades[3]){
  return Avg = ((Grades[0] + Grades[1] + Grades[2]) / 3.0f);
}

void PrintAverageGrades(float Avg, short Grades[3]){
  cout<<"The average of grades is: "<<AverageGrades(Avg, Grades)<<"\n";
  cout<<"Grades:\nAt index 0: "<<Grades[0]<<"\n"
      <<"At index 1: "<<Grades[1]<<"\n"
      <<"At index 2: "<<Grades[2]<<endl;
}

int main()
{
  short Grades[3] = {0, 0, 0};
  float Avg{0};
  ReadGrades(Grades);
  
  PrintAverageGrades(Avg, Grades);
  return 0;
}
