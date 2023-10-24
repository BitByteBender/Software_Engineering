#include <iostream>

using std::cout, std::endl;

int main()
{
  unsigned short Arr[10][10];

  unsigned short i, j, Calc = 0;
  
  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < 10; j++)
    {
      Calc = (j + 1) * (i + 1);
      Arr[i][j] = Calc;
      
      if (Calc < 10)
      {
	putchar('0');
	putchar('0' + Arr[i][j]);
	putchar(' ');
	//cout<<0<<Arr[i][j]<<' ';
      }
      else
      {
	if (j < 9)
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
