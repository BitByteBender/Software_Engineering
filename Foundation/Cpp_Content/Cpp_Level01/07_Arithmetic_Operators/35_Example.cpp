#include <iostream>

int main()
{
  float CashPaid{0.0f}, TotalBill{0.0f};
  float Remainder{0.0f};

  std::cout<<"Enter CashPaid: ";
  std::cin>>CashPaid;

  std::cout<<"Enter TotalBill: ";
  std::cin>>TotalBill;

  Remainder = TotalBill - CashPaid;

  std::cout<<abs(Remainder)<<std::endl;
  
  return 0;
}
