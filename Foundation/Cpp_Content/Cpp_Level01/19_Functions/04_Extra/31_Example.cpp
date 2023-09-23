#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

void CalculatePowerOfNumbers(short& Num1, short& Pow1, short& Pow2, short& Pow3){
  Pow1 = pow(Num1, 2);
  Pow2 = Pow1 * Num1;
  Pow3 = Pow2 * Num1;
}

void PrintPowerOfNumbers(short Num, short Pow1, short Pow2, short Pow3){
  CalculatePowerOfNumbers(Num, Pow1, Pow2, Pow3);
  cout<<Pow1<<"\n"<<Pow2<<"\n"<<Pow3<<endl;
}

int main()
{
  short Num1 = 3;
  short Pow1 = 0, Pow2 = 0, Pow3 = 0;
  PrintPowerOfNumbers(Num1, Pow1, Pow2, Pow3);
  return 0;
}
