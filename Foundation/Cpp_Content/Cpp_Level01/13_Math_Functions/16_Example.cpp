#include <iostream>
#include "math.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
  unsigned short D{0}, H{0}, M{0}, S{0};

  std::string Prompt{"Enter the "};

  cout<<Prompt + "days: ";
  cin>>D;

  cout<<Prompt + "Hours: ";
  cin>>H;

  cout<<Prompt + "Minutes: ";
  cin>>M;

  cout<<Prompt + "Seconds: ";
  cin>>S;

  float TotalSeconds = (D * 86400) + (H * 3600) + (M * 60) + S;
  cout<<"Total Seconds: "<<TotalSeconds<<" Seconds\n";
  cout<<"Result rounded: "<<round(TotalSeconds)<<" Seconds"<<endl;
  return 0;
}
