#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

short ReadNumber(string Message)
{
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

void ReadNumberOfHours(unsigned short *Hours)
{
  *Hours = ReadNumber("Enter number of hours: ");
}

float CalcWeeks(unsigned short Hours)
{
  float Weeks{0.0f};

  Weeks = Hours / (24.0f * 7.0f);
  
  return (Weeks);
}

float CalcDays(unsigned short Hours)
{
  float Days{0};

  Days = Hours / 24.0f;
  
  return (Days);
}

void PrintDaysAndWeeks(float Days, float Weeks)
{
  cout<<"Weeks: "<<CalcWeeks(Weeks)<<"\n";
  cout<<"Days: "<<CalcDays(Days)<<endl;
}

int main()
{
  unsigned short Hours{0}, *ptrHours{nullptr};
  ptrHours = &Hours;
  
  ReadNumberOfHours(ptrHours);
  PrintDaysAndWeeks(*ptrHours, *ptrHours);
  return 0;
}

