#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void ReadSeconds(unsigned int *Secs)
{
  cout<<"How many secs:\n-> ";
  cin>>*Secs;
}

short SecsIntoDays(unsigned int Secs)
{
  return (Secs / (24 * 3600));
}

short SecsIntoHours(unsigned int Secs)
{
  return ((Secs % 86400) / 3600);
}

short SecsIntoMins(unsigned int Secs)
{
  return ((Secs % 3600) / 60);
}

short RemainingSecs(unsigned int Secs)
{
  return (Secs % 60);
}

void PrintResult(unsigned int Days, unsigned int Hours, unsigned int Mins, unsigned int Seconds)
{
  cout<<SecsIntoDays(Days)<<":"<<SecsIntoHours(Hours)<<":"<<SecsIntoMins(Mins)<<":"<<RemainingSecs(Seconds)<<endl;
}
int main()
{
  unsigned int Seconds{0}, *pSecs{nullptr};
  unsigned int Days{0}, Hours{0}, Mins{0};
  pSecs = &Seconds;
  
  ReadSeconds(pSecs);
  
  Days = *pSecs, Hours = *pSecs, Mins = *pSecs;
  PrintResult(Days, Hours, Mins, *pSecs);
  return 0;
}
