#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  short Mark1{0}, Mark2{0}, Mark3{0};
  float Avg{0.0f};

  cout<<"Enter Mark1: ";
  cin>>Mark1;

  cout<<"Enter Mark2: ";
  cin>>Mark2;

  cout<<"Enter Mark3: ";
  cin>>Mark3;

  Avg = (Mark1 + Mark2 + Mark3) / 3.0f;

  cout<<Avg<<endl;
  return 0;
}
