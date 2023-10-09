#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(void)
{
  unsigned short Num{0};

  cout<<"Enter a number: ";
  cin>>Num;

  for (int i = Num; i >= 1; i--) {
    cout<<i<<endl;
  }
  return 0;
}
