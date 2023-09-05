#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  float Base{0.0f}, Height{0.0f};
  float Result{0.0f};
  
  cout<<"Enter the base: ";
  cin>>Base;

  cout<<"Enter the height: ";
  cin>>Height;

  Result = Base * Height;

  cout<<Result<<endl;
  return 0;
}
