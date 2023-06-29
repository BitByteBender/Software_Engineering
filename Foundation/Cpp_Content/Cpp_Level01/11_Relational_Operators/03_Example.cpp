#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main()
{
  short X{0}, Y{0};

  cout<<"Enter the first number(X): ";
  cin>>X;

  cout<<"Enter the second number(Y): ";
  cin>>Y;

  cout<<X<<" == "<<Y<<" is "<<(X == Y)<<"\n";
  cout<<X<<" != "<<Y<<" is "<<(X != Y)<<"\n";
  cout<<X<<" > "<<Y<<" is "<<(X > Y)<<"\n";
  cout<<X<<" < "<<Y<<" is "<<(X < Y)<<"\n";
  cout<<X<<" >= "<<Y<<" is "<<(X >= Y)<<"\n";
  cout<<X<<" <= "<<Y<<" is "<<(X <= Y)<<"\n";
  return 0;
}
