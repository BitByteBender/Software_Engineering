#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
  //Initializing Identifiers
  short FirstNum{0}, SecondNum{0};

  //Inputs
  cout<<"Enter 1st number: ";
  cin>>FirstNum;

  cout<<"Enter 2nd number: ";
  cin>>SecondNum;

  //Outputs
  cout<<FirstNum<<" + "<<SecondNum<<" = "<<FirstNum  + SecondNum<<"\n";
  cout<<FirstNum<<" - "<<SecondNum<<" = "<<FirstNum - SecondNum<<"\n";
  cout<<FirstNum<<" * "<<SecondNum<<" = "<<FirstNum * SecondNum<<"\n";
  cout<<FirstNum<<" / "<<SecondNum<<" = "<<FirstNum / SecondNum<<"\n";
  cout<<FirstNum<<" % "<<SecondNum<<" = "<<FirstNum % SecondNum<<endl;
  return 0;
}
