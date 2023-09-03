#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int MyAge{55};
  int InYears{5};
  int AfterYears= MyAge + InYears;

  cout<<"After "<<InYears<<" years you will be "<<AfterYears<<" years old."<<endl;
  return 0;
}

