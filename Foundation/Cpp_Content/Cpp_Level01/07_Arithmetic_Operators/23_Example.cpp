#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
  //Initialize variables
  string InitialPhrase{"Half of "};
  short Number{0};
  float HalfOfNumber{0.0f};
  //Inputs
  cout<<"Enter a number: ";
  cin>>Number;

  //Calculations
  HalfOfNumber = Number / 2.0f;

  //Outputs
  cout<<InitialPhrase<<Number<<" is "<<HalfOfNumber<<endl;
  return 0;
}
