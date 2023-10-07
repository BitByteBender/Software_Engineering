#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned int TotalSales{0};

  cout<<"Enter the total sales: ";
  cin>>TotalSales;

  if (TotalSales > pow(10, 6)) {
    cout<<float(TotalSales * 0.01)<<endl;
  }else if(TotalSales >  500000){
    cout<<float((TotalSales * 2) / 100)<<endl;
  }else if(TotalSales > 100000){
    cout<<float((TotalSales * 3) / 100)<<endl;
  }else if(TotalSales>50000){
    cout<<float((TotalSales * 5) / 100)<<endl;
  }else{
    cout<<(TotalSales * 0) / 100;
  }
  
  return 0;
}
