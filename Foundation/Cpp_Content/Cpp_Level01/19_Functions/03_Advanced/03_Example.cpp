#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string ReadStrings(string Message){
  string Name;

  cout<<Message;
  cin>>Name;
  
  return Name;
}

void PrintFullName(string Fullname){
  cout<<"your full name is: "<<Fullname<<endl;
}

int main()
{
  string FirstName = ReadStrings("Enter your FirstName: ");
  string LastName  = ReadStrings("Enter your LastName: ");

  string Fullname = FirstName + " " + LastName;
  PrintFullName(Fullname);
  return 0;
}
