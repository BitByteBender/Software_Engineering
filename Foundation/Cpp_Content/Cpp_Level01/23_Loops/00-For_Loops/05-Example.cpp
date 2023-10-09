#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  unsigned short N{0};
  unsigned int Multiplier{1};

  cout<<"Enter a number: ";
  cin>>N;

  cout<<"Factorial of "<<N<<" ---> ";
  for (short i = N; i >= 1; i--) {
    if (i == 1) {
      cout<<i<<" = "<<Multiplier<<endl;
      break;
    }else{
      Multiplier = Multiplier * i;
      cout<<i<<" x ";
    }
  }
  
  return 0;
}
