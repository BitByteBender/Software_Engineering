#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short Days{0}, Hours{0}, Mins{0}, Seconds{0};
  unsigned int TotalInSeconds{0};
  
  cout<<"Enter the days: ";
  cin>>Days;

  cout<<"Enter the hours: ";
  cin>>Hours;

  cout<<"Enter the mins: ";
  cin>>Mins;

  cout<<"Enter the seconds: ";
  cin>>Seconds;

  TotalInSeconds = (Days * 24 * 3600) + (Hours * 3600) + (Mins * 60) + Seconds;

  cout<<TotalInSeconds<<" Seconds"<<endl;
  return 0;
}
