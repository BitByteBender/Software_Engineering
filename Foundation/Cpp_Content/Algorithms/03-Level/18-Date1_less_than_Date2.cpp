#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct stDate
{
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

uint16_t *PromptNum(const char *Message)
{
  uint16_t *Num = (uint16_t *)malloc(sizeof(uint16_t));

  cout<<Message;
  cin>>*Num;

  return (Num);
}

stDate promptData()
{
  stDate dt;

  dt.Day = *PromptNum("Enter a Day: ");
  dt.Month = *PromptNum("Enter a Month: ");
  dt.Year = *PromptNum("Enter a year: ");
  
  cout<<'\n';
  
  return (dt);
}

string DateComparison(stDate dt[2])
{
  string Comp1 = "Yes, Date_1 is less than Date2";
  string Comp2 = "No, Date_1 is not less than Date_2";
  
  if (dt[0].Year < dt[1].Year)
    return (Comp1);
  else {
    if (dt[0].Month < dt[1].Month)
      return (Comp1);
    else if (dt[0].Day < dt[1].Day)
      return (Comp1);
  }

  return (Comp2);
}

void DisplayDateComparison(stDate dt[2])
{
  cout<<DateComparison(dt)<<endl;
}

int main(void)
{
  stDate dt[2] = {promptData(), promptData()};

  DisplayDateComparison(dt);
  return (0);
}
