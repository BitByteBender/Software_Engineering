#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

uint16_t readNum(const string Msg)
{
  uint16_t Num{0};

  cout<<Msg;
  cin>>Num;

  return (Num);
}

bool isleapYear(uint16_t Num)
{
  return ((Num % 4 == 0 && Num % 100 != 0) || Num % 400 == 0);
}

void printLeapOrNot(uint16_t Year)
{
  if (isleapYear(Year)) {
    cout<<"Yes, year ["<<Year<<"] is a Leap year"<<endl; 
  } else {
    cout<<"No, year ["<<Year<<"] isn't a leap year"<<endl;
  }
}

int main(void)
{
  uint16_t Year = readNum("Enter a year: ");

  printLeapOrNot(Year);  
  return (0);
}
