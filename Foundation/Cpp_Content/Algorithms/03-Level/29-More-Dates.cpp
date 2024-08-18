#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct stDate
{
  uint16_t Year;
  uint16_t Month;
  uint16_t Day;
};

uint16_t DataPrompt(const char *Message)
{
  uint16_t Num{0};

  cout<<Message;
  cin>>Num;
  
  return (Num);
}

stDate FeedData()
{
  stDate Date;

  Date.Year = DataPrompt("Enter Year: ");
  Date.Month = DataPrompt("Enter Month: ");
  Date.Day = DataPrompt("Enter Day: ");
  
  return (Date);
}

int main(void)
{
  stDate Date;
  Date = FeedData();

  cout<<"\nDate(Entry): "<<Date.Day<<'/'<<Date.Month<<'/'<<Date.Year<<'\n'<<endl;
  
  return (0);
}
