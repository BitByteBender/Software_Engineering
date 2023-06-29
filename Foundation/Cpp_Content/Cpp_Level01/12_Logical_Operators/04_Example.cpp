#include <iostream>

using std::cout;
using std::endl;


int main()
{
  cout<<(12 >= 12)<<"\n"; //true
  cout<<(12 > 7)<<"\n"; //true
  cout<<(8 < 6)<<"\n"; //false
  cout<<( 8 == 8)<<"\n"; //true
  cout<<(12 <= 12)<<"\n"; //true
  cout<<(7 == 5)<<"\n"; //false
  cout<<!(12 >= 12)<<"\n"; //false
  cout<<!(12 > 7)<<"\n"; //false
  cout<<!(8 < 6)<<"\n"; //true
  cout<<!(8 == 8)<<"\n"; //false
  cout<<!(12 <= 12)<<"\n"; //false
  cout<<!(7 == 5)<<"\n"; //true
  cout<<(1 && 1)<<"\n"; //true
  cout<<(true && 0)<<"\n"; //false
  cout<<(0 || 1)<<"\n"; //true
  cout<<(0 || 0)<<"\n"; //false
  cout<<!0<<"\n"; //true
  cout<<!(1 || 0)<<"\n"; //false
  cout<<((7 == 7) && (7 > 5))<<"\n"; //true
  cout<<((7 == 7) && (7 < 5))<<"\n"; //false
  cout<<((7 == 7) || (7 < 5))<<"\n"; //true
  cout<<((7 < 7) || (7 > 5))<<"\n"; //true
  cout<<(!(7 == 7) && (7 > 5))<<"\n"; //false
  cout<<((7 == 7) && !(7 < 5))<<endl; //true
  return 0;
}
