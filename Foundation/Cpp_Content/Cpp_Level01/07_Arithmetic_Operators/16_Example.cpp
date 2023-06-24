#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  float TotalBill{0}, CashPaid{0};

  cout<<"What's the TotalBill?: ";
  cin>>TotalBill;

  cout<<"How much did you pay?: ";
  cin>>CashPaid;

  float Remainder= TotalBill - CashPaid;
  cout<<abs(Remainder)<<endl;
  return 0;
}

