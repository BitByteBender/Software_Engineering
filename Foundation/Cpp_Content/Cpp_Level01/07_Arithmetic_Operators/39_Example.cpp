#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  float LoanAmount{0.0f}, MonthlyPayment{0.0f};
  short MonthsLeft{0};

  cout<<"Enter the LoanAmount: ";
  cin>>LoanAmount;

  cout<<"Enter the MonthlyPayment: ";
  cin>>MonthlyPayment;

  MonthsLeft = LoanAmount / MonthlyPayment;

  cout<<MonthsLeft<<" Months."<<endl;
  return 0;
}
