#include <iostream>

using std::cout;
using std::endl;

int main()
{
  unsigned short i, j;

  for (i = 1; i <= 10; i++) {
    for (j = i; j <= 10; j++) {
      cout<<j;
      if (j < 10) {
	cout<<" ";
      }
    }
    cout<<"\n";
  }
  cout<<endl;
  
  return 0;
}
