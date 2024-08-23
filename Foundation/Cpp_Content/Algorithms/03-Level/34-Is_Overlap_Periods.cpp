#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum enOrder{Before=-1, Equal=0, After=1};

struct stDate
{
  uint16_t Day;
  uint16_t Month;
  uint16_t Year;
};

struct stDates
{
  stDate pDate1[2];
  stDate pDate2[2];
};

uint16_t ReadNum(const char *Msg)
{
  uint16_t Num{0};

  cout<<Msg;
  cin>>Num;
  
  return (Num);
}

stDate LoadData()
{
  stDate dt;

  dt.Day = ReadNum("Enter a Day: ");
  dt.Month = ReadNum("Enter a Month: ");
  dt.Year = ReadNum("Enter a Year: ");

  return (dt);
}

bool IsDate1AfterDate2(stDate dt1, stDate dt2)
{
  return (dt1.Year > dt2.Year || (dt1.Year == dt2.Year && dt1.Month > dt2.Month) || (dt1.Year == dt2.Year && dt1.Month == dt2.Month && dt1.Day > dt2.Day));
}

bool IsDate1BeforeDate2(stDate dt1, stDate dt2)
{
  return (dt1.Year < dt2.Year || (dt1.Year == dt2.Year && dt1.Month < dt2.Month) || (dt1.Year == dt2.Year && dt1.Month == dt2.Month && dt1.Day < dt2.Day));
}

bool IsDate1EqualDate2(stDate dt1, stDate dt2)
{
  return (dt1.Year == dt2.Year && dt1.Month == dt2.Month && dt1.Day == dt2.Day);
}

enOrder CompareDates(stDate dt1, stDate dt2)
{
  if (IsDate1BeforeDate2(dt1, dt2)) return (enOrder::Before);

  return (IsDate1EqualDate2(dt1, dt2) ? (enOrder::Equal) : (enOrder::After));
}

bool IsOverlap(stDate dt1, stDate dt2)
{
  return (CompareDates(dt1, dt2) == -1);
}

void DisplayResult(stDates dt)
{
  stDate Dt[4] = {dt.pDate1[0], dt.pDate1[1], dt.pDate2[0], dt.pDate2[1]};
  uint16_t i = 0;
  
  for (i = 0; i < 4; ++i) {
    if ((i + 1) % 2 != 0) {
      cout<<"Period "<<(i < 2 ? (i+1) : i)<<":\n";
      cout<<"Enter Start Date:\n";
    } else
      cout<<"Enter End Date:\n";

    Dt[i] = LoadData();
    cout<<'\n';
  }

  i = 0;
  for (const stDate& dt:Dt) {
    cout<<"Date "<<++i<<":> "<<dt.Day<<'/'<<dt.Month<<'/'<<dt.Year<<'\n';
  }

  cout<<"\nDT 0: "<<Dt[1].Day<<'/'<<Dt[1].Month<<'/'<<Dt[1].Year<<'\n';
  cout<<"DT 2: "<<Dt[2].Day<<'/'<<Dt[2].Month<<'/'<<Dt[2].Year<<"\n\n";
  
  cout<<(IsDate1EqualDate2(Dt[1], Dt[2]) ? "Equal" : "Not Equal")<<'\n';
  
  cout<<"\nComparison: "<<CompareDates(Dt[1], Dt[2])<<"\n\n";
  
  if (IsOverlap(Dt[1], Dt[2])) {
    cout<<"\n>>Yes, Periods Overlap"<<endl;
  } else
    cout<<"\n>>No, Periods don't Ovelap"<<endl;
}

int main(void)
{
  stDates P1;
  DisplayResult(P1);
  return (0);
}
