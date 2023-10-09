#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

enum enCars{Ferrari = 'F', Lamborghini = 'L', Mclaren = 'M'};

struct stAddress{
  string City{"empty"}, Country{"empty"};
};

struct stPerson{
  string Fullname{"empty"};
  unsigned short Age{0};
  stAddress Address;
  enCars FavCar;
};

void ReadInfo(stPerson &Person)
{
  cout<<"Enter the Fullname: ";
  cin.ignore(1, '\n');
  getline(cin, Person.Fullname);

  cout<<"Enter your age: ";
  cin.ignore(1, '\n');
  cin>>Person.Age;

  cout<<"Enter City: ";
  cin>>Person.Address.City;

  cout<<"Enter Country: ";
  cin>>Person.Address.Country;

  char Picker{'x'};
  cout<<"What your favourite car: ";
  cin>>Picker;
  Person.FavCar = (enCars)Picker;
 
}

string GetCar(stPerson Person)
{
  switch (Person.FavCar) {
  case enCars::Ferrari:
    return "Ferrari";
  case enCars::Lamborghini:
    return "Lamborghini";
  case enCars::Mclaren:
    return "Mclaren";
    
  default:
    return "Not my favourite car";
  }
}

void DisplayCard(stPerson Person, string CardStyle)
{
  cout<<CardStyle;
  cout<<"Fullname: "<<Person.Fullname<<"\n";
  cout<<"Age: "<<Person.Age<<"\n";
  cout<<"City: "<<Person.Address.City<<"\n";
  cout<<"Country: "<<Person.Address.Country<<"\n";
  cout<<"Fav-Car: "<<GetCar(Person)<<"\n";
  cout<<CardStyle<<"\n";
}

void ReadPersons(stPerson Person[2])
{
  ReadInfo(Person[0]);
  ReadInfo(Person[1]);
}

void DisplayCards(stPerson Person[2], string CardStyle)
{
  DisplayCard(Person[0], CardStyle);
  DisplayCard(Person[1], CardStyle);
}

int main()
{
  stPerson Person[2];

  ReadPersons(Person);
  DisplayCards(Person, "\n************************\n");
  return 0;
}
