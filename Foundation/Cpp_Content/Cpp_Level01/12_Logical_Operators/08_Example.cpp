#include <iostream>

using std::cout;
using std::endl;

int main()
{
   
  cout<<"1 AND 1 => "<<(1 && 1)<<"\n";//True = 1
  cout<<"True AND 0 => "<<(true && 0)<<"\n";//False = 0
  cout<<"0 OR 1 => "<<(0 || 1)<<"\n";//True = 1
  cout<<"0 OR 0 => "<<(0 || 0)<<"\n";//False = 0
  cout<<"Not 0 => "<<!(0)<<"\n";//True = 1
  cout<<"Not(1 OR 0) => "<<!(1 || 0)<<endl;//False = 0

  return 0;
}
