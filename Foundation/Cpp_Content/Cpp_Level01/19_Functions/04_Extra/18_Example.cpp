#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct stPersonData{
  std::string Name{"empty"};
  short Age{0};
  float MonthlySalary{0.0f};
};

stPersonData ReadStruct(){

  stPersonData PersonData;

  cout<<"Your Name: ";
  cin>>PersonData.Name;

  cout<<"Your Age: ";
  cin>>PersonData.Age;

  cout<<"Your MonthlySalary: ";
  cin>>PersonData.MonthlySalary;

  return PersonData;
}

float CalculateYearlySalary(stPersonData PersonData){
  return float(PersonData.MonthlySalary * 12.0f);
}

void PrintPersonData(stPersonData PersonData){
  cout<<"Name: "<<(PersonData.Name)<<"\n";
  cout<<"Age: "<<(PersonData.Age)<<"\n";
  cout<<"MonthlySalary: "<<PersonData.MonthlySalary<<"\n";
  cout<<"YearlySalary: "<<CalculateYearlySalary(PersonData)<<endl;
}

int main()
{
  stPersonData PersonData;
  PrintPersonData(ReadStruct());
  return 0;
}
