#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short i{1}, n{0}, Sum{0};

  cout<<"Enter n: ";
  cin>>n;

  while (i <= n) {

    if (i % 2 == 0) {
      Sum = Sum + i;
    }
    i++;
  }
  
  cout<<Sum<<endl;
  
  return 0;
}
