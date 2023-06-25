#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned int NumberInSeconds{0};

  cout<<"Enter a number in seconds: ";
  cin>>NumberInSeconds;

  unsigned short SecondsInDaysConvertion = NumberInSeconds / 86400;
  unsigned short SecondsInHoursConvertion = (NumberInSeconds % 86400) / 3600;
  unsigned short SecondsInMinutesConvertion = (NumberInSeconds % 3600) /60;
  unsigned short RemainingSeconds = (NumberInSeconds % 60);
  

  cout<<SecondsInDaysConvertion<<":"<<SecondsInHoursConvertion<<":"<<SecondsInMinutesConvertion<<":"<<RemainingSeconds<<endl;
}
