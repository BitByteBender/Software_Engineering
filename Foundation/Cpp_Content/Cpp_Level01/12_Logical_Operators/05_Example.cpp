#include <iostream>

using std::cout;
using std::endl;


int main()
{
  cout<<((5 > 6 && 7 == 7) || (1 || 0))<<"\n"; //true
  cout<<!((5 > 6 && 7 == 7) || (1 || 0))<<"\n"; //false
  cout<<!((5 > 6 && 7 == 7) || !(1 || 0))<<"\n"; //true
  cout<<!((5 > 6 || 7 == 7) && !(1 || 0))<<"\n"; //true
  cout<<(((5 > 6 && 7 <= 8) || (8 > 1 && 4 <= 3)) && true)<<"\n"; //false
  cout<<(((5 > 6 && !(7 <= 8)) && (8 > 1 || 4 <= 3)) || true)<<endl; //true
  return 0;
}
