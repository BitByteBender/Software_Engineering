#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::to_string;

int ReadPositiveNumber(string Message)
{
  int Num{0};
  
  cout<<Message;
  cin>>Num;

  return (Num);
}

void PrintDigit(int Num)
{
  string NumHolder = to_string(Num);
  short i = 1, Remainder{0}, length = NumHolder.length();
  
  while (Num > 0) {

    if (length > 0) {
      length =  pow(10, (NumHolder.length() - i));
      i++;
    }
    
    Remainder = (Num / length);
    Num = Num % length;
    
    cout<<Remainder<<"\n";
  }
  
}

int main()
{
  int Num = ReadPositiveNumber("Enter a number: ");

  PrintDigit(Num);
  return 0;
}
