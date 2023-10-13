#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short i{0}, n;

  cout<<"Enter n: ";
  cin>>n;

  while (i < n) {
    cout<<i+1<<"\n";
    i++;
  }
  cout<<endl;
  
  return 0;
}
