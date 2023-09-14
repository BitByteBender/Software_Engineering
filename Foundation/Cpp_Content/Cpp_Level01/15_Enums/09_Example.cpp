#include <iostream>

using std::cout;
using std::endl;
using std::string;

enum enMaritalStatus{
  Single = 0, Married = 1, Divorced = 3, Widowed = 4
};

enum enGender{ Male = 1, Female};

struct stLocationData{
  string City{"empty"};
  string Country{"empty"};
  string Street{"empty"};
};

struct stPersonData{
  string FirstName{"empty"}, MiddleName{"empty"}, LastName{"empty"};
  unsigned short Age{0};
  stLocationData Location;
  string Phone{"empty"};
  enMaritalStatus MaritalStatus;
  enGender Gender;
};

int main()
{
  stPersonData Person1, Person2;

  Person1.FirstName = "Soufiane";
  Person1.LastName = "Sadgali";
  Person1.Age = 99;
  Person1.Location.City = "Marbella";
  Person1.Location.Country = "Spain";
  Person1.Location.Street = "St1, 1995";
  Person1.Phone = "+2126121345";
  Person1.MaritalStatus = enMaritalStatus::Single;
  Person1.Gender = enGender::Male;

  cout<<"Full name: "<<Person1.FirstName + " " + Person1.LastName<<"\n";
  cout<<"Age: "<<Person1.Age<<"\n";
  cout<<"City: "<<Person1.Location.City<<"\n";
  cout<<"Country: "<<Person1.Location.Country<<"\n";
  cout<<"Street: "<<Person1.Location.Street<<"\n";
  cout<<"Phone: "<<Person1.Phone<<"\n";
  cout<<"MaritalStatus: "<<Person1.MaritalStatus<<"\n";
  cout<<"Gender: "<<Person1.Gender<<"\n\n";

  Person2.FirstName = "Carl";
  Person2.MiddleName = "Maestro";
  Person2.LastName = "Mr.birk";
  Person2.Age = 26;
  Person2.Location.City = "Cape Town";
  Person2.Location.Country = "South Africa";
  Person2.Location.Street = "St1, 1994";
  Person2.Phone = "+230 61-21345";
  Person2.MaritalStatus = enMaritalStatus::Single;
  Person2.Gender = enGender::Male;

  cout<<"Full name: "<<Person2.FirstName + " " + Person2.MiddleName + " " + Person2.LastName<<"\n";
  cout<<"Age: "<<Person2.Age<<"\n";
  cout<<"City: "<<Person2.Location.City<<"\n";
  cout<<"Country: "<<Person2.Location.Country<<"\n";
  cout<<"Street: "<<Person2.Location.Street<<"\n";
  cout<<"Phone: "<<Person2.Phone<<"\n";
  cout<<"MaritalStatus: "<<Person2.MaritalStatus<<"\n";
  cout<<"Gender: "<<Person2.Gender<<endl;
  
  return 0;
}

