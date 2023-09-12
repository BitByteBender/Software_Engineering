#include <iostream>

using std::cout;
using std::endl;

enum enMaritalStatus{Single = 0, Married = 1, Divorced = 2, Widowed = 3};

int main()
{
  enMaritalStatus MyStatus1, MyStatus2, MyStatus3;

  MyStatus1 = enMaritalStatus::Married;
  cout<<"Status1: "<<MyStatus1<<"\n";

  MyStatus2 = enMaritalStatus::Single;
  cout<<"Status2: "<<MyStatus2<<"\n";

  MyStatus3 = enMaritalStatus::Widowed;
  cout<<"Status3: "<<MyStatus3<<endl;
  return 0;
}
