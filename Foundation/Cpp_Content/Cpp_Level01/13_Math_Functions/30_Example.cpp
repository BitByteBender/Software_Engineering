#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  unsigned short D{0}, H{0}, M{0}, S{0};

  cout<<"Enter Days: ";
  cin>>D;

  cout<<"Enter Hours: ";
  cin>>H;

  cout<<"Enter Minutes: ";
  cin>>M;

  cout<<"Enter Seconds: ";
  cin>>S;

  unsigned int TotalSeconds = (D * 24 * 3600) + (H * 3600) + (M * 60) + S;

  cout<<TotalSeconds<<" Seconds\n";
  cout<<"Rounding: "<<round(TotalSeconds)<<endl;
  return 0;
}
