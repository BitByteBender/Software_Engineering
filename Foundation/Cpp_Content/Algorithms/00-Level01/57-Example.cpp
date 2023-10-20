#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

float ReadNumber(string Message)
{
  float Num{0.0f};
  float *ptrNum = &Num;
  
  cout<<Message;
  cin>>*ptrNum;

  return (*ptrNum);
}

void ReadInstalment(float &LoanAmount, short &Month)
{
  LoanAmount = ReadNumber("Enter the loan amount:\n-> $");
  Month = ReadNumber("How many months to settle the loan: ");
}

float CalcInstalmentAmount(float LoanAmount, short Month)
{
  return (LoanAmount / Month);
}

void PrintInstalmentAmount(float InstalmentAmount)
{
  cout<<"Instalment amount: $"<<InstalmentAmount<<endl;
}

int main()
{
  float LoanAmount{0.0f};
  short Month{0};

  ReadInstalment(LoanAmount, Month);
  PrintInstalmentAmount(CalcInstalmentAmount(LoanAmount, Month));
  return (0);
}
