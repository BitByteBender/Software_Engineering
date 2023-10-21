#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ReadBillValue(float *Billvalue)
{
  cout<<"Enter bill value: ";
  cin>>*Billvalue;
}

float CalcTotalBill(float Billvalue)
{
  float TotalBill{0}, ServiceFee{0.1}, SalesTax{0.16};

  ServiceFee = ServiceFee * Billvalue;
  SalesTax = (ServiceFee + Billvalue) * SalesTax;
  TotalBill = Billvalue + ServiceFee + SalesTax;
  
  return TotalBill;
}

void PrintTotalBill(float TotalBill)
{
  cout<<"TotalBill: "<<TotalBill<<endl;
}

int main()
{
  float Billvalue{0};
  float *ptrBillValue = &Billvalue;
  float TotalBill{0}, *ptrTotalBill = &TotalBill;
  
  ReadBillValue(ptrBillValue);
  TotalBill = CalcTotalBill(*ptrBillValue);
  PrintTotalBill(*ptrTotalBill);
  return 0;
}
