#include <iostream>
#include "math.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned int Seconds{0};

  cout<<"Enter the time in seconds: ";
  cin>>Seconds;

  unsigned short SecondsIntoDays = (Seconds / (24 * 3600));
  unsigned short SecondsIntoHours = (Seconds % (24*3600) / 3600);
  unsigned short SecondsIntoMinutes = (Seconds % 3600) / 60;
  unsigned short RemainingSeconds = (Seconds % 60);

  cout<<SecondsIntoDays<<":"<<SecondsIntoHours<<":"<<SecondsIntoMinutes<<":"<<RemainingSeconds<<endl;
  return 0;
}
