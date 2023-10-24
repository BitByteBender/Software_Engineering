#include <iostream>

using std::cout, std::endl;

int main()
{
  unsigned short Arr[11][11];

  unsigned short i, j;
  
  for (i = 1; i <= 10; i++)
  {
    Arr[i][0] = i;
    for (j = 1; j <= 10; j++)
    {
      Arr[i][j] = (j * i);
      if ((i * j) < 10)
      {
	putchar('0');
	cout<<Arr[i][j]<<' ';
      }
      else
      {
	if (j < 10)
	{
	  cout<<Arr[i][j]<<' ';
	}
	else
	{
	cout<<Arr[i][j];
	}
      }
    }
    cout<<"\n";
  }
  cout<<endl;
  
  return (0);
}
