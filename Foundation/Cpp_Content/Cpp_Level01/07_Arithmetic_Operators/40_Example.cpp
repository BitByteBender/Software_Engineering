#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  float LoanAmount{0.0f};
  short Months{0};

  cout<<"Enter the LoanAmount: ";
  cin>>LoanAmount;

  cout<<"How many months: ";
  cin>>Months;

  float MonthlyInstallmentAmount = LoanAmount / Months;

  cout<<MonthlyInstallmentAmount<<endl;
  return 0;
}
