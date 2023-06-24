#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Days{0}, Hours{0}, Minutes{0}, Seconds{0};

  cout<<"Enter Days: ";
  cin>>Days;

  cout<<"Enter Hours: ";
  cin>>Hours;

  cout<<"Enter Minutes: ";
  cin>>Minutes;

  cout<<"Enter Seconds: ";
  cin>>Seconds;

  unsigned int DaysInSeconds = Days * 86400;
  unsigned int HoursInSeconds = Hours * 3600;
  unsigned int MinutesInSeconds = Minutes * 60;
  unsigned int TotalSeconds = Seconds + DaysInSeconds + HoursInSeconds + MinutesInSeconds;
  cout<<TotalSeconds<<endl;

  return 0;
}
