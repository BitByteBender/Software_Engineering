#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

short ReadNumber(string Message)
{
  short Num{0};

  cout<<Message;
  cin>>Num;
  
  return (Num);
}

short CalculateExponent(short Num, short M)
{
  unsigned short i, Exponent{Num};

  for (i = 1; i < M; i++) {
    Exponent = Exponent * (Num);
  }
  
  return (Exponent);
}

void PrintPowerOfM(short Product)
{
  cout<<"Product: "<<Product<<endl;
  
}

int main()
{
  short Num{0}, M{0}, Product{0};

  Num = ReadNumber("Enter the base: ");
  M = ReadNumber("Enter the Exponent: ");

  Product = CalculateExponent(Num, M);
  PrintPowerOfM(Product);
  return 0;
}

