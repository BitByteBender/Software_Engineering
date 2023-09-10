#include <iostream>

using std::cout;
using std::endl;

int main()
{
    
  cout<<"Not(12 >= 12) => "<<!(12 >= 12)<<"\n";//False = 0
  cout<<"Not(12 < 7) => "<<!(12 < 7)<<"\n";//True = 1
  cout<<"Not(8 < 6) => "<<!(8 < 6)<<"\n";//True = 1
  cout<<"Not(8 == 8) => "<<!(8 == 8)<<"\n";//False = 0
  cout<<"Not(12 <= 12) => "<<!(12 <= 12)<<"\n";//False = 0
  cout<<"Not(7 == 5) => "<<!(7 == 5)<<endl;//True = 1

  return 0;
}
