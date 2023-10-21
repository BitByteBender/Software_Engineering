#include <iostream>

using std::cout;
using std::endl;

int main()
{
  unsigned short i, j;

  for (i = 0; i < 10; i++) {
    for (j = 1; j <= (i + 1); j++) {
      cout<<(j);
      if (j <= i) {
	cout<<" ";
      }
    }
    cout<<"\n";
  }
  cout<<endl;
  
  return 0;
}
