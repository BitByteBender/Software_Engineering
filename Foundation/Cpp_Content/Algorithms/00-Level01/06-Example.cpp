#include <iostream>

using std::cout;
using std::endl;

int main()
{
  unsigned short i, j;

  for (i = 65; i <= 90; i++)
  {
    for (j = 65; j <= 90; j++) {
      cout<<char(i)<<char(j)<<"\n";
    }
  }

  cout<<endl;
  
  return 0;
}
