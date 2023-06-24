#include <iostream>


using std::cout;
using std::cin;
using std::endl;


int main()
{
  float BillValue{0};

  cout<<"Enter your billvalue: ";
  cin>>BillValue;

  float ServiceFee = BillValue * 10 / 100 + BillValue;
  float SalesTax = ServiceFee * 16 / 100;
  float TotalBill = ServiceFee + SalesTax;
  cout<<TotalBill<<endl;
  
  return 0;
}
