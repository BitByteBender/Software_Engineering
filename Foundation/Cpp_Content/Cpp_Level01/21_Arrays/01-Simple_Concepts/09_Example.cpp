#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short ArrayOfNumbers[4] = {0, 0, 0, 0};

  cout<<"Enter 1st grade: ";
  cin>>ArrayOfNumbers[0];

  cout<<"Enter 2nd grade: ";
  cin>>ArrayOfNumbers[1];

  cout<<"Enter 3rd grade: ";
  cin>>ArrayOfNumbers[2];

  cout<<"Enter 4th grade: ";
  cin>>ArrayOfNumbers[3];

  cout<<"ArrayOfNumbers at index 0: "<<ArrayOfNumbers[0]<<"\n";
  cout<<"ArrayOfNumbers at index 1: "<<ArrayOfNumbers[1]<<"\n";
  cout<<"ArrayOfNumbers at index 2: "<<ArrayOfNumbers[2]<<"\n";
  cout<<"ArrayOfNumbers at index 3: "<<ArrayOfNumbers[3]<<"\n";

  float AvgGrades = (ArrayOfNumbers[0] + ArrayOfNumbers[1] + ArrayOfNumbers[2] + ArrayOfNumbers[3]) / 4.0f;

  cout<<"Average Grades: "<<AvgGrades<<endl;
  return 0;
}
