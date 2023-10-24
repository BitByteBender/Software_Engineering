#include <iostream>

using std::cout, std::endl;

void PrintNums(short From, short To)
{
  if (From <= To) {
    cout<<From<<"\n";
    PrintNums((From + 1), To);
  }
}
int main()
{
  PrintNums(1, 5);
  cout<<endl;
  return 0;
}
