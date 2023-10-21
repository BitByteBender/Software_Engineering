#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

struct stInstalment
{
  float LoanAmount{0.0f};
  float MonthlyPayment{0.0f};
};

float *ReadNumber(string Message)
{
  float Num{0.0f};
  float *ptrNum = &Num;
  
  cout<<Message;
  cin>>*ptrNum;

  return (ptrNum);
}

void ReadInstalment(stInstalment &Instalment)
{
  Instalment.LoanAmount = *ReadNumber("Loan amount: ");
  Instalment.MonthlyPayment = *ReadNumber("MonthlyPayment: ");
}

short CalcMonths(stInstalment Instalment)
{
  return (Instalment.LoanAmount / Instalment.MonthlyPayment);
}

void PrintMonths(stInstalment Instalment)
{
  cout<<CalcMonths(Instalment)<<" Months"<<endl;
}

int main()
{
  stInstalment Instalment;

  ReadInstalment(Instalment);
  PrintMonths(Instalment);
  return 0;
}

