#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned int Seconds{0};
  unsigned short SecondsToDays{0}, SecondsToHours{0}, SecondsToMins{0}, RemainingSeconds{0};

  cout<<"Enter seconds: ";
  cin>>Seconds;

  SecondsToDays = Seconds / (24 * 3600);
  SecondsToHours = (Seconds % (24 * 3600)) / 3600;
  SecondsToMins = (Seconds % 3600) / 60;
  RemainingSeconds = Seconds % 60;
  cout<<SecondsToDays<<":"<<SecondsToHours<<":"<<SecondsToMins<<":"<<RemainingSeconds<<endl;
  return 0;
}
