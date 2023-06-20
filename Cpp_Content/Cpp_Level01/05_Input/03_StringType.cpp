#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string Prompt {"What's your firstname? "};
  cout<<Prompt;

  string FirstName{"Empty"};
  cin>>FirstName;
  
  Prompt = "What's your lastname? ";
  cout<<Prompt;
 
  string SecondName{"Empty"};
  cin>>SecondName;
  
  string FullName = FirstName +" "+ SecondName;
  cout<<"My FullName is "<<FullName<<"\n";
  cout<<"My FullName is "<<FirstName<<" "<<SecondName<<"\n";
  cout<<"My FullName is "<<FirstName + " " + SecondName<<endl;
  return 0;
}
