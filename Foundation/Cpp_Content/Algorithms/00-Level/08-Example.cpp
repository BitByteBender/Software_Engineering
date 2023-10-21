#include <iostream>

using std::cout;
using std::endl;

int main()
{

  unsigned short i, j, n{10};

  for (i = n; i >= 1; i--) {
    for (j = 1; j <= i ; j++) {
      cout<<"*";
    }
    cout<<"\n";
  }
  cout<<endl;
  
  return 0;
}
