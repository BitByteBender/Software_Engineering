#include <iostream>

using std::cout;
using std::endl;

int main()
{
  bool MyBoolean{false};
  cout<<MyBoolean<<"\n";

  MyBoolean = true;
  cout<<MyBoolean<<"\n";

  MyBoolean = 0;
  cout<<MyBoolean<<"\n";
  
  MyBoolean = 1;
  cout<<MyBoolean<<endl;
  
  return 0;
}
