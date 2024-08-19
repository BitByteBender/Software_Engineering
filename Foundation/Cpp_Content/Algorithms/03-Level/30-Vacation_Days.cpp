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

void PrintInfo(stDateData Dt[2])
{
  cout<<"Vacation From: "<<Dt[0].Day<<'/'<<Dt[0].Month<<'/'<<Dt[0].Year<<endl;
  cout<<"Vacation To: "<<Dt[1].Day<<'/'<<Dt[1].Month<<'/'<<Dt[1].Year<<endl;
}

int main(void)
{
  stDateData Dt[2];
  
  cout<<"Vacation Starts:\n";
  Dt[0] = DataLoader();
  cout<<endl;
  
  cout<<"Vacation Ends:\n";
  Dt[1] = DataLoader();
  cout<<endl;
  
  PrintInfo(Dt);
  
  return (0);
}
