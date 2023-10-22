#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

short ReadPositiveNumber(string Message)
{
  short Number{0};

  do {
    cout<<Message;
    cin>>Number;
  } while (Number<=0);
  
  return (Number);
}

void PrintIsolatedNumbers(short &Num)
{
  short Remainder{0};

  while (Num != 0) {
    Remainder = Num % 10;
    Num = Num / 10;
    cout<<Remainder<<endl;
  }

}


int main()
{
  short Num = ReadPositiveNumber("Enter a number: ");
  PrintIsolatedNumbers(Num);
  return 0;
}

