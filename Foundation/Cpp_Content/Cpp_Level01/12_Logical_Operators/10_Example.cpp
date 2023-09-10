#include <iostream>

using std::cout;
using std::endl;

int main()
{
  cout<<"(5 > 6 and 7 = 7) || (1 or 0) => "<<((5 > 6 && 7 == 7) || (1 || 0))<<"\n";//True = 1
  cout<<"Not(5 > 6 and 7 = 7) Or (1 or 1) => "<<(!(5 > 6 && 7 == 7) || (1 || 1))<<"\n";//True = 1
  cout<<"Not(5 > 6 Or 7 = 7) AND Not(1 || 0) => "<<(!(5 > 6 || 7 == 7) && !(1 || 0))<<"\n";//False = 0
  cout<<"((5 > 6 AND 7 <= 8) Or (8 > 1 And 4 <= 3)) AND True => "<<((5 > 6 && 7 <= 8) || (8 > 1 && 4 <= 3) && true)<<"\n";//False = 0
  cout<<"((5 > 6 AND Not(7 <= 8)) AND (8 > 1 OR 4 <= 3)) => "<<((5 > 6 && !(7 <= 8)) && (8 > 1 || 4 <= 3) || true)<<"\n";//True = 1
  return 0;
}
