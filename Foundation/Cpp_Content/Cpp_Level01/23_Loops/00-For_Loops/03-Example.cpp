#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(void)
{
  unsigned short Num{0}, Sum{0};
  cout<<"Enter a number: ";
  cin>>Num;

  for (int i = 1; i <= Num; i++) {
    if (i % 2 != 0) {
      Sum = Sum + i;
    }
    
  }
  cout<<Sum<<endl;
  return 0;
}
