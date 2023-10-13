#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct stPerson
{
  string FirstName{"empty"}, LastName{"empty"};
  unsigned short Age{0};
  string Phone{"empty"};
};

void ReadPersonInfo(stPerson &Person)
{
  cout<<"Enter firstname: ";
  cin>>Person.FirstName;

  cout<<"Enter lastname: ";
  cin>>Person.LastName;

  cout<<"Enter age: ";
  cin>>Person.Age;

  cout<<"Enter phone: ";
  cin>>Person.Phone;
}

void PrintPersonInfo(stPerson Person, string CardStyle)
{
  cout<<CardStyle
      <<"FirstName: "<<Person.FirstName<<"\n"
      <<"LastName: "<<Person.LastName<<"\n"
      <<"Age: "<<Person.Age<<"\n"
      <<"Phone: "<<Person.Phone<<"\n"
      <<CardStyle<<endl;
}

void ReadPersonsInfo(stPerson Person[10], unsigned short &Length)
{
  cout<<"How many persons? ";
  cin>>Length;
  
  unsigned short i;

  do {
    cout<<"Person "<<i+1<<" Info:\n";
    ReadPersonInfo(Person[i]);
    i++;
  } while (i <= Length - 1);
}

void DisplayPersonsInfo(stPerson Person[10], unsigned short Length, string CardStyle)
{
  unsigned short i;

  for (i = 0; i <= Length - 1; i++) {
    cout<<"\nPerson "<<i+1<<" Info:\n";
    PrintPersonInfo(Person[i], CardStyle);
  }
}

int main()
{
  stPerson Person[10];
  unsigned short Length{0};
  string CardStyle = "****************************\n";

  ReadPersonsInfo(Person, Length);
  DisplayPersonsInfo(Person, Length, CardStyle);
  return 0;
}
