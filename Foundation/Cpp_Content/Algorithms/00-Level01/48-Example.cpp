#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void ReadCash(float *TotalBill, float *CashPaid)
{
  cout<<"Enter totalbill: ";
  cin>>*TotalBill;

  cout<<"Enter CashPaid: ";
  cin>>*CashPaid;
}

float Remainder(float TotalBill, float CashPaid)
{
  return (CashPaid - TotalBill);
}

void PrintRemainder(float Remainder)
{
  cout<<abs(Remainder)<<endl;
}

int main()
{
  float TotalBill{0}, CashPaid{0};
  float *ptrTotalBill{nullptr}, *ptrCashPaid = {nullptr};
  ptrTotalBill = &TotalBill;
  ptrCashPaid = &CashPaid;
  
  ReadCash(ptrTotalBill, ptrCashPaid);
  float Rmdr = Remainder(TotalBill, CashPaid);
  PrintRemainder(Rmdr);
  
  return 0;
}
