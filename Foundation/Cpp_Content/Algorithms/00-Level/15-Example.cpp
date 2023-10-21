#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct stFullName
{
  string FirstName{"empty"}, LastName{"empty"};
};

void ReadFullName(stFullName &Fullname)
{
  cout<<"Enter your first name: ";
  cin>>Fullname.FirstName;

  cout<<"Enter your last name: ";
  cin>>Fullname.LastName;
}

void PrintFullName(stFullName &Fullname)
{
  cout<<"Fullname: "<<Fullname.FirstName + " " + Fullname.LastName<<endl;
}

int main()
{
  stFullName FullName;

  ReadFullName(FullName);
  PrintFullName(FullName);
  return 0;
}
