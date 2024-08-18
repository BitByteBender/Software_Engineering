#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum enWeekDaysMapper{Su = 0, Mo = 1, Tu = 2, We = 3, Th = 4, Fr = 5, Sa = 6};

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

uint16_t GregorianCalc(stDate Date)
{
  uint16_t a = 0, y = 0, m = 0, Day = 0;

  a = abs((14 - Date.Month) / 12);
  y = Date.Year - a;
  m = Date.Month + (12 * a) - 2;

  Day = (Date.Day + y + abs(y/4) - abs(y/100) + abs(y/400) + abs((31 * m) / 12)) % 7;
  
  return (Day);
}

string DaysMapper(uint16_t Day)
{ 
  switch (Day) {
  case (enWeekDaysMapper::Su):
    return "Sunday";
  case (enWeekDaysMapper::Mo):
    return "Monday";
  case (enWeekDaysMapper::Tu):
    return "Tuesday";
  case (enWeekDaysMapper::We):
    return "Wednesday";
  case (enWeekDaysMapper::Th):
    return "Thursday";
  case (enWeekDaysMapper::Fr):
    return "Friday";
  case (enWeekDaysMapper::Sa):
    return "Saturday";
  default:
    return "Not a Weekday!";
  }
}

string IsEndOfWeek(string WeekDay)
{
  return (WeekDay != "Sunday" ? "No, Not end of week." : "Yes, It is.");
}

string IsWeekEnd(enWeekDaysMapper WD)
{
  if (WD == 0 || WD == 6)
    return "Yes, it is a weekend.";
  else
    return "No, It is not!";
}

void DisplayInfo(stDate Date)
{
  string DayMapper = DaysMapper(GregorianCalc(Date));
  enWeekDaysMapper WD = (enWeekDaysMapper) GregorianCalc(Date);
  
  cout<<"\nToday is "<<DayMapper<<", "
      <<"DD:"<<Date.Day<<" MM:"<<Date.Month<<" YY:"<<Date.Year<<"\n\n";

  cout<<"Is it End Of Week?\n"<<IsEndOfWeek(DayMapper)<<"\n\n";

  cout<<"Is it Weekend?\n"<<IsWeekEnd(WD)<<"\n\n";
}

int main(void)
{
  stDate Date;
  Date = FeedData();

  DisplayInfo(Date);
  
  return (0);
}
