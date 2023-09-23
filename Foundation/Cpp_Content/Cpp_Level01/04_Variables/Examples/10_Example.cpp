#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
  //Type VariableName/Identifier Assignment Value
  int Age{15};// int Age = 15;
  cout<<"Age: "<<Age<<"\n";

  string NewlineString{"\n\n"};
  cout<<"NewlineString: "<<NewlineString<<"test\n";

  Age = 29;
  cout<<"now Age is: "<<Age<<NewlineString;

  string StrNum1{"115"}, StrNum2{"6"};
  cout<<StrNum1 + StrNum2<<"\n";

  int Num1{15}, Num2{5};
  cout<<Num1 + Num2<<"\n";
  
  string ConcatenateString1{"Al"}, ConcatenateString2{"ha"};
  cout<<ConcatenateString1 + 'p' + ConcatenateString2<<"\n";

  char C1{'L'}, C2{'o'}, C3{'p'};
  cout<<C1 + C2 + 'o' + C3<<"\n";
  return 0;
}
