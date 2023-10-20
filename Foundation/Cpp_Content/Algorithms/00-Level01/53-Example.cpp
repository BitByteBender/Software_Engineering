#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum enWeekDays{Mon = 'M', Tue = 'T', Wed = 'W', Thu = 'H', Fri = 'F', Sat = 'S', Sun = 'N'};

char ReadChars(std::string Message)
{
  char Character{'x'};

  cout<<Message;
  cin>>Character;

  return Character;
}

void ReadList(std::string Card)
{
  cout<<"Enter a character as provided below:\n";
  cout<<Card;
  cout<<"(M) -> Monday"<<"\n";
  cout<<"(T) -> Tuesday"<<"\n";
  cout<<"(W) -> Wednesday"<<"\n";
  cout<<"(H) -> Thursday"<<"\n";
  cout<<"(F) -> Friday"<<"\n";
  cout<<"(S) -> Saturday"<<"\n";
  cout<<"(N) -> Sunday"<<"\n";
  cout<<Card<<endl;
}

enWeekDays ReadWeekDay()
{
  enWeekDays Days;
  char DaysPicker = ReadChars("Pick a day: ");

  return (Days = (enWeekDays) DaysPicker);
}

std::string PickWeekDays(enWeekDays Days)
{
  switch (Days) {
  case (enWeekDays::Mon):
    return "Monday";
  case (enWeekDays::Tue):
    return "Tuesday";
  case (enWeekDays::Wed):
    return "Wednesday";
  case (enWeekDays::Thu):
    return "Thursday";
  case (enWeekDays::Fri):
    return "Friday";
  case (enWeekDays::Sat):
    return "Saturday";
  case (enWeekDays::Sun):
    return "Sunday";
  default:
    return "Not a Week day!";
  }
}

void PrintDay(std::string Day)
{
  cout<<"You have picked: "<<Day<<endl;
}

int main()
{
  std::string DayPicked, Card{"******************\n"};

  ReadList(Card);
  DayPicked = PickWeekDays(ReadWeekDay());
  PrintDay(DayPicked);
  return 0;
}
