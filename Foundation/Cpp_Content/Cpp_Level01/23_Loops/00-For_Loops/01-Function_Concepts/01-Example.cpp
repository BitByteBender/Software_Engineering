#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void ReadNumber(unsigned short &Number, std::string Message)
{

  cout<<Message;
  cin>>Number;

}

void PrintNumbers(unsigned short Numbers){

  for (unsigned short i = Numbers; i >= 1; i--) {
    cout<<i<<"\n";
  }
  cout<<endl;
}

int main()
{
  unsigned short Number{0};
  ReadNumber(Number, "Enter a number: ");
  PrintNumbers(Number);
  return 0;
}
