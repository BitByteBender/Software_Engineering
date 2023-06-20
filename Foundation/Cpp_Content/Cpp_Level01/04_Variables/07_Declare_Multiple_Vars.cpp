#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
  short A, B;
  A = 1;
  B = A;
  string Result = "A + B = ";

  cout<<Result<<A + B<<"\n";

  A = 5;
  B = 7;
  
  cout<<Result<<A+B<<"\n";

  short C = 15;
  short D = A + B;
  short Total = C + D;
  Result = "Total is: ";

  cout<<Result<<Total<<"\n";

  char E = 'A';//This equals 65 in code ASCII
  cout<<int(E)<<"\n";//This is casting just to verify the numerical value of var E (don't pay attention to this line)
  Total = Total + E;//Total = 27 + E = 65
  cout<<Result<<Total<<endl;//This should equal a total of 92
  return 0;
}
