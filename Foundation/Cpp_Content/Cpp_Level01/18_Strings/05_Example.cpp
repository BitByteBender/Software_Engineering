#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string FirstString{"Empty"};
  string SecondString{"Empty"};
  string ThirdString{"Empty"};
  
  cout<<"Enter the 1st string: ";
  getline(cin, FirstString);

  cout<<"Enter the 2nd string: ";
  cin>>SecondString;

  cout<<"Enter the 3rd string: ";
  cin>>ThirdString;
  
  cout<<"**************************\n";
  cout<<"The length of the 1st string is: "<<FirstString.length()<<"\n";

  cout<<"Character at index 0: "<<FirstString[0]<<"\n"
      <<"Character at index 2: "<<FirstString[2]<<"\n"
      <<"Character at index 4: "<<FirstString[4]<<"\n"
      <<"Character at index 7: "<<FirstString[7]<<"\n";

  cout<<"Concatenating SecondString with ThirdString equals: "<<SecondString + ThirdString<<"\n";
  cout<<SecondString + '+' + ThirdString + " = " <<stoi(SecondString) + stoi(ThirdString)<<"\n";
  cout<<SecondString + '*' +  ThirdString + " = " <<stoi(SecondString) * stoi(ThirdString)<<endl;

  return 0;
}
