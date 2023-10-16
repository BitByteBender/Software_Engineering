#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

struct stCoins
{
  unsigned short Penny{0}, Nickel{0}, Dime{0}, Quarter{0};
  float Dollar{0.0f};
};

unsigned short ReadNumber(string Message)
{
  unsigned short Num{0};

  cout<<Message;
  cin>>Num;
  
  return Num;
}

void ReadCoins(stCoins &Coin)
{
  Coin.Penny = ReadNumber("Enter pennies: ");
  Coin.Nickel = ReadNumber("Enter nickels: ");
  Coin.Dime = ReadNumber("Enter dimes: ");
  Coin.Quarter = ReadNumber("Enter quarters: ");
  Coin.Dollar = (float)ReadNumber("Enter dollars: ");
}

unsigned short ConvertCoinsToPennies(stCoins Coin)
{
  return ((Coin.Penny * 1) + (Coin.Nickel * 5) + (Coin.Dime * 10) + (Coin.Quarter * 25) + (Coin.Dollar * 100));
}

float ConvertPennyToDollar(stCoins Coin)
{
  return ((float)ConvertCoinsToPennies(Coin) / 100.0f);
}

void PrintCoins(stCoins Coin)
{
  cout<<"Pennies: "<<ConvertCoinsToPennies(Coin)<<"\n";
  cout<<"Dollars: "<<ConvertPennyToDollar(Coin)<<endl;
}
int main()
{
  stCoins Coin;

  ReadCoins(Coin);
  PrintCoins(Coin);
  return 0;
}
