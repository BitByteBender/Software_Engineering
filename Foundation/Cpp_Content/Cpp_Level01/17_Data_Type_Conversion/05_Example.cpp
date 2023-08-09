#include <iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

int main()
{
  string str1{"5824.7565"};

  int IntegerNumber = stoi(str1);
  
  float FloatNumber = stof(str1);

  double DoubleNumber = stod(str1);

  cout<<"String To Integer: "<<IntegerNumber<<"\n"
      <<"String To Float: "<<FloatNumber<<"\n"
      <<"String To Double: "<<DoubleNumber<<endl;
      
  return 0;
}
