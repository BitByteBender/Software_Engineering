#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
  string St1{"Empty"}, St2{"Empty"}, St3{"Empty"};

  cout<<"Please enter your Fullname: ";
  getline(cin, St1);

  cout<<"\nPlease enter string2: ";
  cin>>St2;

  cout<<"\nPlease enter string3: ";
  cin>>St3;

  string PrintStars{"**************************\n"};

  cout<<PrintStars;
  cout<<"The length of String1 is "<<St1.length()<<"\n";
  cout<<"Characters at 0, 2, 3, 6 are: "<<St1[0]<<" "<< St1[2]<<" "<<St1[3]<< " "<< St1[6]<<"\n";
  cout<<"Concatenating string2 with string3 = "<<St2+St3<<"\n";
  cout<<"Total of "<<St2 <<" * "<<St3 <<" = "<<stoi(St2) * stoi(St3)<<endl;
  return 0;
}
