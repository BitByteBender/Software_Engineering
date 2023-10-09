#include <iostream>

using std::cout;
using std::endl;
using std::cin;

unsigned short ReadNumber(std::string Message)
{
  unsigned short N{0};

  cout<<Message;
  cin>>N;

  return N;
}

void PrintNumbers(unsigned short Numbers){

  for (unsigned short i = 1; i <= Numbers; i++) {
    cout<<i<<"\n";
  }
  cout<<endl;
}

int main()
{
  unsigned short Number = ReadNumber("Enter a number: ");
  PrintNumbers(Number);
  return 0;
}
