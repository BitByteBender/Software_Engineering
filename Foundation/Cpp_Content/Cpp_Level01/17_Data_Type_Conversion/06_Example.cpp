#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

int main()
{
  string str1{"43.22"};
  cout<<"String to float: "<<stof(str1)<<"\n";
  cout<<"String to int: "<<stoi(str1)<<"\n";
  cout<<"STring to double: "<<stod(str1)<<"\n";

  int Num1{20};
  cout<<"Integer to string: "<<to_string(Num1)<<"\n";

  double Num2{32.578};
  cout<<"Double to string: "<<to_string(Num2)<<"\n";

  float Num3{55.23};
  cout<<"Float to string: "<<to_string(Num3)<<endl;
  return 0;
}
