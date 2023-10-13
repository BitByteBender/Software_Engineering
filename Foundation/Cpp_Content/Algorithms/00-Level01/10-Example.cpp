#include <iostream>

using std::cout;
using std::endl;

int main()
{
  unsigned short i, j;

  for (i = 10; i >= 1; i--) {
    for (j = 0; j <= (i - 1); j++) {
      cout<<j+1;
      if (j <= i) {
	cout<<" ";
      }
    }
    cout<<"\n";
  }

  cout<<endl;
  
  return 0;
}
