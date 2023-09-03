#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int AhmedAge{25};
  int SoufianeAge{29};
  int Total = AhmedAge + SoufianeAge;
  cout<<"Total Age is: "<<Total<<"\n";
  
  SoufianeAge = 55;
  Total = AhmedAge + SoufianeAge;
  cout<<"Total Age is: "<<Total<<endl;
  return 0;
}
