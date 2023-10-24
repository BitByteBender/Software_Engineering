#include <iostream>

using std::cout;
using std::endl;

void PrintNumsReversed(short From, short To)
{
  if (From <= To) {
    cout<<To<<"\n";
    PrintNumsReversed(From, (To - 1));
  }
}
int main()
{
  PrintNumsReversed(1, 10);
  return 0;
}
