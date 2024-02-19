#include <iostream>
#include <string.h>
#include <ctime>

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

uint16_t randomizer(uint16_t from, uint16_t to)
{
  return (rand() % (to - from + 1) + from);
}

uint16_t Month2(uint16_t Year)
{
  return (isleapYear(Year) ? 29 : 28);
}

uint16_t monthSwitcher(uint16_t Month, uint16_t Year)
{
  switch (Month) {
  case (1):
    return (Month = 31);
  case (2):
    return (Month = Month2(Year));
  case (3):
    return (Month = 31);
  case (4):
    return (Month = 30);
  case (5):
    return (Month = 31);
  case (6):
    return (Month = 30);
  case (7):
    return (Month = 31);
  case (8):
    return (Month = 30);
  case (9):
    return (Month = 31);
  case (10):
    return (Month = 30);
  case (11):
    return (Month = randomizer(30, 31));
  case (12):
    return (Month = 31);
  default:
    cout<<"Not a month"<<endl;
  }
  
  return (0);
}

uint16_t calcDays(uint16_t Month, uint16_t Year)
{
  return (monthSwitcher(Month, Year));
}

uint16_t calcHours(uint16_t Month, uint16_t Year)
{
  return (monthSwitcher(Month, Year) * 24);
}

unsigned long calcMins(uint16_t Month, uint16_t Year)
{
  return (calcHours(Month, Year) * 60);
}

unsigned long long calcSecs(uint16_t Month, uint16_t Year)
{
  return (calcMins(Month, Year) * 60);
}

void printResult(uint16_t Month, uint16_t Year)
{
  cout<<"Number of days  in ["<<Month<<"]: "<<calcDays(Month, Year)<<'\n';
  cout<<"Number of Hours in ["<<Month<<"]: "<<calcHours(Month, Year)<<'\n';
  cout<<"Number of Mins  in ["<<Month<<"]: "<<calcMins(Month, Year)<<'\n';
  cout<<"Number of Secs  in ["<<Month<<"]: "<<calcSecs(Month, Year)<<'\n';
}

int main(void)
{
  srand(unsigned(time(NULL)));
	
  uint16_t Year = readNum("Enter a year: ");
  uint16_t Month = readNum("Enter a month: ");
  
  printResult(Month, Year);  
  return (0);
}
