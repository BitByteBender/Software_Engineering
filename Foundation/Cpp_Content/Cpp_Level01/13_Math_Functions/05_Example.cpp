#include <iostream>
#include "math.h"

using std::cout;
using std::endl;

int main()
{
  float X{782.54f}, Y{4865.432f};

  cout<<X<<"\n"<<Y<<"\n";
  cout<<ceil(X)<<"\n"<<ceil(Y)<<"\n";
  cout<<floor(X)<<"\n"<<floor(Y)<<"\n";
  cout<<ceil(1.9)<<"\n"<<floor(1.9)<<"\n";
  cout<<ceil(1.1)<<"\n"<<floor(1.1)<<"\n";
  cout<<ceil(-3.9)<<"\n"<<floor(-3.9)<<"\n";
  cout<<ceil(-3.1)<<"\n"<<floor(-3.1)<<endl;
  return 0;
}
