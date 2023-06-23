#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  short Grade1{0}, Grade2{0}, Grade3{0};
  string Prompt{"Enter your grade "};
  cout<<Prompt<<"1: ";
  cin>>Grade1;

  cout<<Prompt<<"2: ";
  cin>>Grade2;

  cout<<Prompt<<"3: ";
  cin>>Grade3;

  //Remember use PEMDAS
  float Avg = (Grade1 + Grade2 + Grade3) / 3.0f;
  cout<<"Average of entered grades is: "<<Avg<<endl;
  return 0;
}
