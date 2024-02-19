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

uint16_t calcDays(uint16_t Year)
{
  return (isleapYear(Year) ? 366 : 365);
}

uint16_t calcHours(uint16_t Year)
{
  return (calcDays(Year) * 24);
}

unsigned long calcMins(uint16_t Year)
{
  return (calcHours(Year) * 60);
}

unsigned long long calcSecs(uint16_t Year)
{
  return (calcMins(Year) * 60);
}


void printResult(uint16_t Year)
{
  cout<<"Number of days  in ["<<Year<<"]: "<<calcDays(Year)<<'\n';
  cout<<"Number of Hours in ["<<Year<<"]: "<<calcHours(Year)<<'\n';
  cout<<"Number of Mins  in ["<<Year<<"]: "<<calcMins(Year)<<'\n';
  cout<<"Number of Secs  in ["<<Year<<"]: "<<calcSecs(Year)<<'\n';
}

int main(void)
{
  uint16_t Year = readNum("Enter a year: ");

  printResult(Year);  
  return (0);
}
