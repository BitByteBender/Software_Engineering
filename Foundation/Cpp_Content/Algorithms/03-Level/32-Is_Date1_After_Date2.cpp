#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct stDate
{
  uint16_t Day, Month, Year;
};

stDate LoadRecord()
{
  stDate Dt;

  cout<<"Enter Day: ";
  cin>>Dt.Day;

  cout<<"Enter Month: ";
  cin>>Dt.Month;

  cout<<"Enter Year: ";
  cin>>Dt.Year;
  
  return (Dt);
}

bool IsDate1AfterDate2(stDate Dates[2])
{
  return (Dates[0].Year > Dates[1].Year || ((Dates[0].Year >= Dates[1].Year && Dates[0].Month > Dates[1].Month) || (Dates[0].Year >= Dates[1].Year && Dates[0].Month >= Dates[1].Month && Dates[0].Day > Dates[1].Day)));
}

void PrintResult(stDate Dates[2])
{
  uint16_t i = 0;

  for (i = 0; i < 2; ++i) {
    cout<<"Enter Date"<<(i+1)<<":\n";
    Dates[i] = LoadRecord();
    cout<<'\n';
  }

  if (IsDate1AfterDate2(Dates)) {
    cout<<"Yes, Date1 is After Date2"<<endl;
  } else {
    cout<<"No, Date1 is Before Date2"<<endl;
  }
}

int main(void)
{
  stDate Dt[2];

  PrintResult(Dt);
  return (0);
}
