#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum enCompare {Before = -1, Equal = 0, After = 1};

struct stDates
{
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

uint16_t ReadNum(const char *Msg)
{
  uint16_t Num{0};

  cout<<Msg;
  cin>>Num;
  
  return (Num);
}

stDates LoadRec()
{
  stDates DT;

  DT.Day = ReadNum("Enter a day: ");
  DT.Month = ReadNum("Enter a month: ");
  DT.Year = ReadNum("Enter a year: ");
  
  return (DT);
}

int16_t CompareDates(const stDates DT[2])
{
  if (DT[0].Year > DT[1].Year || (DT[0].Year == DT[1].Year && DT[0].Month > DT[1].Month) || (DT[0].Year == DT[1].Year && DT[0].Month == DT[1].Month && DT[0].Day > DT[1].Day)) {
    return (enCompare::After);
  }
  
  return (DT[0].Year == DT[1].Year && DT[0].Month == DT[1].Month && DT[0].Day == DT[1].Day ? enCompare::Equal : enCompare::Before);
}

void DisplayResult(stDates DT[2])
{
  uint16_t i = 1;
  
  for (; i <= 2; ++i) {
    cout<<"Enter Date"<<i<<":\n";
    DT[i-1] = LoadRec();
    cout<<'\n';
  }

  cout<<'\n'<<"Compare Result = "<<CompareDates(DT)<<endl;
}

int main(void)
{
  stDates DT[2];
  DisplayResult(DT); 
  return (0);
}
