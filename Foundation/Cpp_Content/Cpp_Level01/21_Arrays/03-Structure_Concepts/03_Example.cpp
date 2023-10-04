#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct strPerson{
  string Firstname{"Empty"}, LastName{"Empty"};
  unsigned short Age{0};
  string Phone{"Empty"};
};

void ReadPersonData(strPerson &Person){
  cout<<"What's your firstname: ";
  cin>>Person.Firstname;

  cout<<"What's your lastname: ";
  cin>>Person.LastName;

  cout<<"How old are you: ";
  cin>>Person.Age;

  cout<<"What's your phone number: ";
  cin>>Person.Phone;
}

void DisplaySingleCard(strPerson Person, string Style){
  cout<<Style<<"\n"
      <<"Firstname: "<<Person.Firstname<<"\n"
      <<"LastName: "<<Person.LastName<<"\n"
      <<"Age: "<<Person.Age<<"\n"
      <<"Phone: "<<Person.Phone<<"\n"
      <<Style<<endl;
}

void ReadPersonsData(strPerson Person[2]){
  ReadPersonData(Person[0]);
  ReadPersonData(Person[1]);
}

void DisplayAllCards(strPerson Person[2], string Style){
  DisplaySingleCard(Person[0], Style);
  DisplaySingleCard(Person[1], Style);
}

int main()
{
  strPerson Person[2];
  string Style = "******************************";
  ReadPersonsData(Person);
  DisplayAllCards(Person, Style);
  return 0;
}
