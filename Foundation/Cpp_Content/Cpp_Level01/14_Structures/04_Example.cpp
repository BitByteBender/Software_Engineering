#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct stAdr{
  string Adr_1{"st404, Penthouse"}, Adr_2{"st1001, Bentley Villa"};
};

struct stContactDetails{
  string PhoneNum_1{"+879797971"}, PhoneNum_2{"+1975121887"};
  stAdr Adr;
};

struct stPersonInfos{
  string FirstName{"Milani"};
  string MiddleName{"Empty"};
  string LastName{"Olumn"};
  unsigned short Age{30};
  string City{"Milan"};
  string Country{"Italy"};
  char Gender{'F'};
  bool isMarried{false};
  stContactDetails ContactDetails;
};

int main()
{
  stPersonInfos Person1, Person2;
  string PrintStars{"**********************************"};

  cout<<PrintStars<<"\n"
      <<"First name: "<<Person1.FirstName<<"\n"
      <<"Last name: "<<Person1.LastName<<"\n"
      <<"Age: "<<Person1.Age<<"\n"
      <<"City: "<<Person1.City<<"\n"
      <<"Country: "<<Person1.Country<<"\n"
      <<"Gender: "<<Person1.Gender<<"emale"<<"\n"
      <<"Married: "<<Person1.isMarried<<"\n"
      <<"Adr: "<<Person1.ContactDetails.Adr.Adr_1<<"\n"
      <<"Phone: "<<Person1.ContactDetails.PhoneNum_1<<"\n"
      <<PrintStars<<"\n";

  Person2.FirstName = "Souf";
  Person2.MiddleName = "Slayer";
  Person2.LastName = "Sadgali";
  Person2.Age = 29;
  Person2.City = "Bznk";
  Person2.Country = "Maruecos";
  Person2.Gender = 'M';
  Person2.isMarried = false;
  Person2.ContactDetails.Adr.Adr_1 = "st44, Big Tower";
  Person2.ContactDetails.Adr.Adr_2 = "st47, Penthouse";
  Person2.ContactDetails.PhoneNum_1 = "+21287968541";
  Person2.ContactDetails.PhoneNum_2 = "+198524784";
    
  cout<<PrintStars<<"\n"
      <<"First name: "<<Person2.FirstName<<"\n"
      <<"Middle name: "<<Person2.MiddleName<<"\n"
      <<"Last name: "<<Person2.LastName<<"\n"
      <<"Age: "<<Person2.Age<<"\n"
      <<"City: "<<Person2.City<<"\n"
      <<"Country: "<<Person2.Country<<"\n"
      <<"Gender: "<<Person2.Gender<<"ale"<<"\n"
      <<"Married: "<<Person2.isMarried<<"\n"
      <<"Adr1: "<<Person2.ContactDetails.Adr.Adr_1<<"\n"
      <<"Adr2: "<<Person2.ContactDetails.Adr.Adr_2<<"\n"
      <<"Phone1: "<<Person2.ContactDetails.PhoneNum_1<<"\n"
      <<"Phone2: "<<Person2.ContactDetails.PhoneNum_2<<"\n"
      <<PrintStars<<endl;
  
    
  return 0;
}
