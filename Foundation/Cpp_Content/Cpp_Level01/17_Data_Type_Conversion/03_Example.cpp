#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

int main()
{
  int FirstNum = 870;
  float SecondNum{78.84f};
  double ThirdNum{54.9071};

  string StrNumber1, StrNumber2, StrNumber3{"Empty"};

  StrNumber1 = to_string(FirstNum); 
  cout<<StrNumber1<<"\n";
 
  StrNumber2 = to_string(SecondNum); 
  cout<<StrNumber2<<"\n";

  StrNumber3 = to_string(ThirdNum);
  cout<<StrNumber3<<endl;
  
  return 0;
}
