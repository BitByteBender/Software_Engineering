#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(void)
{
  unsigned short N{0};

  cout<<"Enter a number: ";
  cin>>N;

  for (int i = 1; i <= N; ++i) {
    cout<<i<<endl;
  }
  return 0;
}
