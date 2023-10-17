#include <iostream>

using std::cout;
using std::endl;
using std::cin;

short ReadNumber(std::string Message)
{
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

bool PrimeOrNot(short Num)
{

    if (Num % 2 == 0) {
      return (0);
    }
    else
    {
      return (1);
    }

}

void PrintPrimeOrNotPrime(short Num)
{
  if (PrimeOrNot(Num) == 1) {
    cout<<"Prime"<<endl;
  }
  else
  {
    cout<<"Not Prime"<<endl;
  }
}

int main()
{
  short Num = ReadNumber("Enter a number: ");
  PrintPrimeOrNotPrime(Num);
  return 0;
}
