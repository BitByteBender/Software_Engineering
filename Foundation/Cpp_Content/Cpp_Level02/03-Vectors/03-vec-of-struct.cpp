#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

enum enGender
{
  Male = 0,
  Female = 1
};

struct stPerson
{
  string fullName;
  uint16_t Age;
  enGender Gender;
};

int main(void)
{
  stPerson Person1, Person2, Person3;
  vector <stPerson> Persons;
  
  Person1.fullName = "lodwig supreme";
  Person1.Age = 45;
  Person1.Gender = (enGender::Male);

  Person2.fullName = "Malak aubrey";
  Person2.Age = 27;
  Person2.Gender = (enGender::Female);

  Person3.fullName = "Sung Gweeo";
  Person3.Age = 31;
  Person3.Gender = (enGender::Male);

  
  
  Persons.push_back(Person1);
  Persons.push_back(Person2);
  Persons.push_back(Person3);

  for (stPerson &Person : Persons) {
    cout<<Person.fullName<<'\n';
    cout<<Person.Age<<'\n';
    cout<<(Person.Gender == 1 ? "Female" : "Male")<<'\n';
    cout<<endl;
  }
  
  return (0);
}
