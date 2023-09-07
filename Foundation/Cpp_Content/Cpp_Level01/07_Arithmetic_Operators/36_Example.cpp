#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  float BillValue{0.0f};
  
  cout<<"Enter the BillValue: ";
  cin>>BillValue;

  float ServicesFee = (BillValue * 0.1f) + BillValue;
  float TaxSales = (ServicesFee * 0.16f) + ServicesFee;

  cout<<TaxSales<<endl;
  return 0;
}
