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
  uint16_t *ptrNum;
  
  ptrNum = PromptNum("Enter a Day: ");
  dt.Day = *ptrNum;
  free(ptrNum);
  
  ptrNum = PromptNum("Enter a Month: ");
  dt.Month = *ptrNum;
  free(ptrNum);
  
  ptrNum = PromptNum("Enter a year: ");
  dt.Year = *ptrNum;
  free(ptrNum);
  cout<<'\n';
  
  return (dt);
}

bool DateComparison(stDate dt[2])
{
  if (dt[0].Year == dt[1].Year && dt[0].Month == dt[1].Month && dt[0].Day == dt[1].Day)
    return (true);
  else
    return (false);
}

void DisplayDateComparison(stDate dt[2])
{
  if (DateComparison(dt)) {
    cout<<"Yes, Date_1 Equals Date_2"<<endl;
  } else {
    cout<<"No, Date_1 doesn't Equal Date_2"<<endl;
  }
}

int main(void)
{
  stDate dt[2] = {promptData(), promptData()};

  DisplayDateComparison(dt);
  return (0);
}
