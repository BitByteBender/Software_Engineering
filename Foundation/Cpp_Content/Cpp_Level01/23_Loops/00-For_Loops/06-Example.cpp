#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(void)
{
  unsigned short Number{0}, PowerUp{0}, Multiplier{0};

  cout<<"Enter a number: ";
  cin>>Number;

  cout<<"Enter the PowerUp: ";
  cin>>PowerUp;

  for (size_t i = 1; i <= PowerUp; ++i) {
    Multiplier = Multiplier + (Number * Number);
  }

  cout<<Multiplier<<endl;
  return 0;
}
