#include <iostream>

using std::cout;
using std::endl;

int main()
{
  
  cout<<"(7 = 7) and (7 > 5) => "<<((7 == 7) && (7 > 5))<<"\n";//True = 1
  cout<<"(7 = 7) and (7 < 5) => "<<((7 == 7) && (7 < 5))<<"\n";//False = 0
  cout<<"(7 = 7) or (7 < 5) => "<<((7 == 7) ||(7 < 5))<<"\n";//True = 1
  cout<<"(7 < 7) or (7 > 5) => "<<((7 < 7) || (7 > 5))<<"\n";//True = 1
  cout<<"Not(7 = 7) && (7 > 5) => "<<(!(7 == 7) && (7 > 5))<<"\n";//False = 0
  cout<<"Not((7 = 7) && (7 > 5)) => "<<!((7 == 7) && (7 > 5))<<"\n";//False = 0
  cout<<"(7 = 7) && !(7 < 5) => "<<((7 == 7) && !( 7 < 5))<<endl;//True = 1
  return 0;
}