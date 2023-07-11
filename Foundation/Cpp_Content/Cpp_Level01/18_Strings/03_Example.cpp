#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
  string st1{"85"}, st2{"115"};

  string st3 = st1 + st2;
  cout<<st3<<"\n";

  int Sum = stoi(st1) + stoi(st2);
  cout<<Sum<<endl;
  return 0;
}
