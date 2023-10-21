#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

enum enMonths
{
  January = 1,
  February = 2,
  March = 3,
  April = 4,
  May = 5,
  June = 6,
  July = 7,
  August = 8,
  September = 9,
  October = 10,
  November = 11,
  December = 12,

};

short ReadNumber(std::string Message)
{
  short Num{0};

  cout<<Message;
  cin>>Num;

  return Num;
}

void ReadList(std::string Card)
{
  cout<<"Enter a number as provided below:\n";
  cout<<Card;
  cout<<"(1) -> January"<<"\n";
  cout<<"(2) -> February"<<"\n";
  cout<<"(3) -> March"<<"\n";
  cout<<"(4) -> April"<<"\n";
  cout<<"(5) -> May"<<"\n";
  cout<<"(6) -> June"<<"\n";
  cout<<"(7) -> July"<<"\n";
  cout<<"(8) -> August"<<"\n";
  cout<<"(9) -> September"<<"\n";
  cout<<"(10) -> October"<<"\n";
  cout<<"(11) -> November"<<"\n";
  cout<<"(12) -> December"<<"\n";
  cout<<Card<<endl;
}

enMonths ReadMonth()
{
  enMonths Month;
  char MonthPicker = ReadNumber("Pick a Month: ");

  return (Month = (enMonths) MonthPicker);
}

std::string PickMonth(enMonths Month)
{
  switch (Month) {
  case (enMonths::January):
    return "January";
  case (enMonths::February):
    return "February";
  case (enMonths::March):
    return "March";
  case (enMonths::April):
    return "April";
  case (enMonths::May):
    return "May";
  case (enMonths::June):
    return "June";
  case (enMonths::July):
    return "July";
  case (enMonths::August):
    return "August";
  case (enMonths::September):
    return "September";
  case (enMonths::October):
    return "October";
  case (enMonths::November):
    return "November";
  case (enMonths::December):
    return "December";
  default:
    return "a Wrong Month!";
  }
}

void PrintMonth(enMonths Month)
{
  cout<<"You have picked: "<<PickMonth(Month)<<endl;
}

int main()
{
  enMonths Month;
  std::string Card{"******************\n"};

  ReadList(Card);
  ReadMonth();
  PrintMonth(Month);
  return 0;
}
