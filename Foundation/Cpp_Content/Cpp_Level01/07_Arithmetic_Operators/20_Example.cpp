#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main()
{

  unsigned short LoanInstallment{0}, MonthlyLoan{0};

  cout<<"What's your Loan Installment?: ";
  cin>>LoanInstallment;

  cout<<"How much do you pay monthly?: ";
  cin>>MonthlyLoan;

  unsigned short MonthsToPay=LoanInstallment / MonthlyLoan;

  cout<<MonthsToPay<< " Months"<<endl;
  return 0;
}
