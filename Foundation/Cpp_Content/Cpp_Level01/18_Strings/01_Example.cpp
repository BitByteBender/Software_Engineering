#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string Fullname{"Empty"};
  short Age{0};

  cout<<"Enter your fullname: ";
  getline(cin, Fullname);
 
  cout<<"Enter your age: ";
  cin>>Age;

  cout<<"Fullname: "<<Fullname<<"\n";
  cout<<"Age: "<<Age<<endl;
  
  return 0;
}
