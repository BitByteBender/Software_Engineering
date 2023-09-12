#include <iostream>

using std::cout;
using std::endl;

enum enSchoolStatus{High = 20, Mid = 32, College = 47};

int main()
{
  enSchoolStatus SchoolStatus1, SchoolStatus2, SchoolStatus3;

  SchoolStatus1 = enSchoolStatus::Mid;
  cout<<"SchoolStatus1: "<<SchoolStatus1<<"\n";

  SchoolStatus2 = enSchoolStatus::High;
  cout<<"SchoolStatus2: "<<SchoolStatus2<<"\n";

  SchoolStatus3 = enSchoolStatus::College;
  cout<<"SchoolStatus3: "<<SchoolStatus3<<endl;
  return 0;
}
