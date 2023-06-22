#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short Number{0};
  cout<<"Enter a number: ";
  cin>>Number;

  float HalfOfANumber = Number / 2.0f;
  cout<<"Half of "<<Number<<" is "<<HalfOfANumber<<endl;
  return 0;
}
