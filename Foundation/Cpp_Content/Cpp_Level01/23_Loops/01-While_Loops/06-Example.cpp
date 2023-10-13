#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short i{0}, Number{2}, M{4}, Total{1};

  i = 0;
  while (i < M) {
    Total = Total * Number;
    i++;
  }

  cout<<Total<<endl;
  return 0;
}
