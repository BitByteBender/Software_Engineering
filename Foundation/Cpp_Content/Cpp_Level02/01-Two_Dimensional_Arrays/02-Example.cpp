#include <iostream>

using std::cout;
using std::endl;

int main()
{
  unsigned short Arr[10][5];
  unsigned short i, j, Calc = 0;
  
  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < 5; j++)
    {
      Calc = (j + 1) * (i + 1);
      Arr[i][j] = Calc;
    }
  }

  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < 5; j++)
    {
      if (j < 9) {
	printf("%0*d ", 3, Arr[i][j]);
      }
      else
      {
	printf("%0*d", 3, Arr[i][j]);
      }
    }
    cout<<"\n";
  }
  
  cout<<endl;
  
  return (0);
}
