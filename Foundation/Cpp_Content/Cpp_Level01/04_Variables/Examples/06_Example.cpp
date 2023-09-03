#include <iostream>

using std::cout;
using std::endl;

int main()
{
  const int MinutesPerHour{60};
  int TotalHours = (MinutesPerHour * 2) / 60;
  cout<<"Hours: "<<TotalHours<<endl;
  return 0;
}
