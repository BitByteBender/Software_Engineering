#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct strInfo{
  string Firstname{"Empty"}, LastName{"Empty"};
  short Age{0};
  string Phone{"Empty"};
};

int main()
{
  strInfo PersonInfo[2];
  PersonInfo[0].Firstname = "Oussama";
  PersonInfo[0].LastName = "Atif";
  PersonInfo[0].Age = 36;
  PersonInfo[0].Phone = "+212-6789235";

  PersonInfo[1].Firstname = "Soufiane";
  PersonInfo[1].LastName = "Sedki";
  PersonInfo[1].Age = 54;
  PersonInfo[1].Phone = "+978256435";

  cout<<"Fullname: "<<PersonInfo[0].Firstname + ' ' + PersonInfo[0].LastName<<"\n"
      <<"Age: "<<PersonInfo[0].Age<<"\n"
      <<"Phone: "<<PersonInfo[0].Phone<<"\n\n";

  
  cout<<"Fullname: "<<PersonInfo[1].Firstname + ' ' + PersonInfo[1].LastName<<"\n"
      <<"Age: "<<PersonInfo[1].Age<<"\n"
      <<"Phone: "<<PersonInfo[1].Phone<<endl;

  
  return 0;
}
