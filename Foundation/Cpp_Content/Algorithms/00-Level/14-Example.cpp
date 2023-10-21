#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct stEmployeeInfo
{
  unsigned short Age{0};
  bool hasDriverlicense{false};
  bool HasRecommendation{false};
};

void ReadEmployeeInfo(stEmployeeInfo &Employee)
{
  cout<<"Does he have recommendations(Y=1/N=0)?: ";
  cin>>Employee.HasRecommendation;
  
  cout<<"Enter Age: ";
  cin>>Employee.Age;

  cout<<"Has driver license(Y=1/N=0)?: ";
  cin>>Employee.hasDriverlicense;
}

string HiredOrRejected(stEmployeeInfo Employee)
{
  if (Employee.HasRecommendation)
  {
    return "Hired";
  }
  else
  {
    return ((Employee.Age == 21 && Employee.hasDriverlicense) ? "Hired" : "Rejected");
  }
}

void PrintDecision(stEmployeeInfo Employee)
{
  cout<<"Decision: "<<HiredOrRejected(Employee)<<endl;
}

int main()
{
  stEmployeeInfo Employee;
  ReadEmployeeInfo(Employee);
  PrintDecision(Employee);
  return 0;
}
