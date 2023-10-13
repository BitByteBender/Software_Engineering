#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short i{0}, n{0}, Factorial{1};

  cout<<"Enter n: ";
  cin>>n;

  i = n;
  while (i >= 1) {
    Factorial = Factorial * i;
    i--;
  }
  
  cout<<Factorial<<endl;
  
  return 0;
}
