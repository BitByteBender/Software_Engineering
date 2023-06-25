#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main()
{
  unsigned short LoanInstallment{0}, Months{0};

  cout<<"How much is your LoanInstallment?: ";
  cin>>LoanInstallment;

  cout<<"How many months you would like to settle the loan?: ";
  cin>>Months;

  unsigned short MonthlyPayment = LoanInstallment / Months;
  cout<<"You will need to pay "<<MonthlyPayment<<" Monthly."<<endl;
  return 0;
}
