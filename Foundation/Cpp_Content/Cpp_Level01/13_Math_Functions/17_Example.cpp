#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned int Seconds{0};

  cout<<"Enter Seconds: ";
  cin>>Seconds;

  short ConvertToDays = (Seconds / 86400);
  short ConvertToHours = (Seconds % 86400) / 3600;
  short ConvertToMinutes = (Seconds % 3600) / 60;
  short RemainingSeconds = (Seconds % 60);

  cout<<ConvertToDays<<" : "<<ConvertToHours<<" : "<<ConvertToMinutes<<" : "<<RemainingSeconds<<endl;
  return 0;
}
