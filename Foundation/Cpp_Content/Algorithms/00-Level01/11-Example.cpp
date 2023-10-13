#include <iostream>

using std::cout;
using std::endl;

int main()
{
  unsigned short i;
  char j;

  for (i = 0; i <= 5; i++) {
    for (j = 'A'; j <= char(i + 65); j++) {
      cout<<j;
      if ((int(j) - 65) < i) {
	cout<<" ";
      }
    }
    cout<<"\n";
  }


  cout<<endl;
  
  return 0;
}
