#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

unsigned short ReadNumber(string Message){
  short Number{0};

  cout<<Message;
  cin>>Number;

  return Number;
}

int CalculateTaskDurationInSeconds(short Days, short Hours, short Mins, short Seconds){
  return (Days * 24 * 60 * 60 ) + (Hours * 60 * 60) + (Mins * 60) + Seconds;
}

void PrintTaskDurationInSeconds(int Duration){
  cout<<Duration<<" Seconds"<<endl;
}

int main()
{
  short Days = ReadNumber("How many days? ");
  short Hours = ReadNumber("How many hours? ");
  short Mins = ReadNumber("How many mins? ");
  short Seconds = ReadNumber("How many seconds? ");
  PrintTaskDurationInSeconds(CalculateTaskDurationInSeconds(Days, Hours, Mins, Seconds));
  return 0;
}
