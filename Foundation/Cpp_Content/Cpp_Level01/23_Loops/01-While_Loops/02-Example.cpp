#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short i{0}, n;

  cout<<"Enter n: ";
  cin>>n;

  i = n;
  while (i >= 1) {
    cout<<i<<"\n";
    i--;
  }
  cout<<endl;
  
  return 0;
}
