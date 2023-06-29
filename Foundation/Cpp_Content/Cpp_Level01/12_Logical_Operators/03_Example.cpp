#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  bool Result{!(57 <= 15 || 19 == 19 ) && (0 || true) || !(75>76 && 15>=35)};

  cout<<Result<<endl;//Not(false or true) And (true) or Not(false And false) = true
  return 0;
}
