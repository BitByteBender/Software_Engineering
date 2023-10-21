#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void ReadMark(short &Mark)
{
  cout<<"Enter a number: ";
  cin>>Mark;
}

std::string CheckMark(short Mark)
{
  return (Mark >= 50 ? "PASS" : "FAIL");
}

void PrintResult()
{
  short Mark = 0;
  ReadMark(Mark);
  cout<<CheckMark(Mark)<<endl;
}

int main()
{
  PrintResult();
  return 0;
}

