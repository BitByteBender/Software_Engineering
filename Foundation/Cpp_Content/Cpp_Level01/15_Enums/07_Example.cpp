#include <iostream>

using std::cout;
using std::endl;

enum enRanch{Small = 0, Medium = 1, Large = 2, ExtraLarge = 3};

int main()
{
  enRanch Ranch1, Ranch2;

  Ranch1 = enRanch::Small;
  cout<<"Ranch1: "<<Ranch1<<"\n";

  Ranch2 = enRanch::ExtraLarge;
  cout<<"Ranch2: "<<Ranch2<<endl;
  return 0;
}
