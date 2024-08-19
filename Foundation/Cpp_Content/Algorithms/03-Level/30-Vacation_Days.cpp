#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct stDateData
{
  uint16_t Day, Month, Year;
};

uint16_t *DataPrompt(const char *Msg)
{
  uint16_t *ptrNum = new uint16_t;

  cout<<Msg;
  cin>>*ptrNum;
  
  return (ptrNum);
}

stDateData DataLoader()
{
  stDateData Date;

  uint16_t *Day = DataPrompt("Enter a Day: ");
  uint16_t *Month = DataPrompt("Enter a Month: ");
  uint16_t *Year = DataPrompt("Enter a Year: ");

  Date.Day = *Day;
  Date.Month = *Month;
  Date.Year = *Year;

  delete Day;
  delete Month;
  delete Year;
  
  return (Date);
}

int main(void)
{
  stDateData Dt;
  Dt = DataLoader();

  cout<<"Vacation From: "<<Dt.Day<<'/'<<Dt.Month<<'/'<<Dt.Year<<endl;
  return (0);
}
