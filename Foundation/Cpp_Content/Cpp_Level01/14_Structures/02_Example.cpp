#include <iostream>
#include <math.h>

using std::cout;
using std::endl;
using std::string;

struct strDetails{
  string Adr_1{"st 404, NY Tower"};
  string Adr_2{"st 405, Trump Tower"};
};

struct strPerson{
  string FirstName{"Soufiane"};
  string MiddleName{"Empty"};
  string LastName{"Sadgali"};
  unsigned short Age{29};
  strDetails Details;
};

int main()
{
  strPerson Person_1, Person_2;

  cout<<"********************\n"

      <<"FirstName: "<<Person_1.FirstName<<"\n"
      <<"LastName: "<<Person_1.LastName<<"\n"
      <<"Age: "<<Person_1.Age<<"\n"
      <<"1st Adr: "<<Person_1.Details.Adr_1<<"\n"
      <<"2nd Adr: "<<Person_1.Details.Adr_2<<"\n"
      <<"*********************\n";


  Person_2.FirstName = "Jackie";
  Person_2.MiddleName = "Aubrey";
  Person_2.LastName = "Amber";
  Person_2.Age = 24;
  Person_2.Details.Adr_1 = "Oklahoma, 10001";
  Person_2.Details.Adr_2 = "Oklahoma, 20002";

  cout<<"*********************\n"

      <<"FirstName: "<<Person_2.FirstName<<"\n"
      <<"LastName: "<<Person_2.LastName<<"\n"
      <<"Age: "<<Person_2.Age<<"\n"
      <<"1st Adr: "<<Person_2.Details.Adr_1<<"\n"
      <<"2nd Adr: "<<Person_2.Details.Adr_2<<"\n"
      <<"**********************"<<endl;

  
  return 0;
}


  
  
