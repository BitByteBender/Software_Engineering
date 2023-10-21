#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

unsigned int ReadNumber(string Message)
{
  unsigned int Num{0};

  cout<<Message;
  cin>>Num;
  
  return Num;
}

void ReadTotalSales(unsigned int &TotalSales)
{
  TotalSales = ReadNumber("Enter total sales: ");
}

float CalculateTotalSales(unsigned int TotalSales)
{
  if (TotalSales > pow(10, 6)) {
    return (TotalSales * 0.01f);
  }
  else if(TotalSales > (5 * pow(10,  5)))
  {
    return (TotalSales * 0.02f);
  }
  else if(TotalSales > pow(10, 5))
  {
    return ((TotalSales * 3) / 100);
  }
  else if (TotalSales > (5 * pow(10, 4)))
  {
    return ((TotalSales * 5) / 100);
  }
  else
  {
    return ((TotalSales * 0) / 100);
  }
}

void PrintCommission(float Commission)
{
  cout<<"Commission: "<<(float)CalculateTotalSales(Commission)<<endl;
}

int main()
{
  unsigned int TotalSales{0};

  ReadTotalSales(TotalSales);
  PrintCommission(TotalSales);
  return 0;
}
