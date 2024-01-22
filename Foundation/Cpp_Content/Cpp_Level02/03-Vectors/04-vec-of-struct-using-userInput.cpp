#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct stPerson
{
  string fullName;
  uint16_t Age;
  float salary;
};

void readData(vector <stPerson> &vPersons)
{
  stPerson tempPerson;
  char cond{'x'};
  
  cout<<"Enter data:\n";

  do {
    cout<<"Person fullname: ";
    getline(cin, tempPerson.fullName);
    
    
    cout<<"Person's Age: ";
    cin>>tempPerson.Age;

    cout<<"Person's salary: ";
    cin>>tempPerson.salary;

    vPersons.push_back(tempPerson);

    cout<<"Do you wanna continue? ";
    cin>>cond;
    cin.ignore(1, '\n');
    
  } while (cond == 'y' || cond == 'Y');
  
}

void printPersonsData(vector <stPerson> &vPersons)
{
  cout<<"\nVector of structures:\n";
  
  for (stPerson &Person : vPersons) {
    cout<<"fullName: "<<Person.fullName<<'\n';
    cout<<"Age: "<<Person.Age<<'\n';
    cout<<"Salary: "<<Person.salary<<'\n';
    cout<<endl;
  }
}

int main(void)
{
  vector <stPerson> vPersons;

  readData(vPersons);
  printPersonsData(vPersons);
  return (0);
}
