#include <iostream>

using std::cout, std::cin;
using std::endl;

int main()
{
  int x[3][4] =
  {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };

  unsigned short i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      cout<<x[i][j];
      if (x[i][j] == 12)
      {
	putchar('.');
      }
      else
      {
	putchar(',');
	putchar(' ');
      }
    }
  }
  cout<<endl;
  
  return 0;
}
