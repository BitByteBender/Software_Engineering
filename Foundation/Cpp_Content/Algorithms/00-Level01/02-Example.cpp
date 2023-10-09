#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

enum enColors{Red = 0, Black = 1};
enum enCars{Ferrari = 'F', Lamborghini = 'L', Mclaren = 'M'};
enum enGender{Male = 'M', Female = 'F'};

struct stAddress{
  string City{"empty"}, Country{"empty"};
};

struct stPerson{
  string Fullname{"empty"};
  unsigned short Age{0};
  stAddress Address;
  enGender Gender;
  enCars FavCar;
  enColors FavColor;
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

  char GenderPicker{'X'};
  cout<<"Your Gender: ";
  cin>>GenderPicker;
  Person.Gender = (enGender)GenderPicker;
  
  char Picker{'x'};
  cout<<"What your favourite car: ";
  cin>>Picker;
  Person.FavCar = (enCars)Picker;

  bool ColorPicker{false};
  cout<<"What's your favourite color?: ";
  cin>>ColorPicker;
  Person.FavColor = (enColors)ColorPicker;
}

string GetGender(stPerson Person)
{
  switch (Person.Gender) {
  case enGender::Male:
    return "Male";
  case enGender::Female:
    return "Female";
    
  default:
    return "Not a gender";
  }
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

string GetColor(stPerson Person)
{
  switch (Person.FavColor) {
  case enColors::Red:
    return "Red";
  case enColors::Black:
    return "Black";
     
  default:
    return "Not my favourite color";
  }
}

void DisplayCard(stPerson Person, string CardStyle)
{
  cout<<CardStyle;
  cout<<"Fullname: "<<Person.Fullname<<"\n";
  cout<<"Age: "<<Person.Age<<"\n";
  cout<<"City: "<<Person.Address.City<<"\n";
  cout<<"Country: "<<Person.Address.Country<<"\n";
  cout<<"Gender: "<<GetGender(Person)<<"\n";
  cout<<"Fav-Car: "<<GetCar(Person)<<"\n";
  cout<<"Fav-Color: "<<GetColor(Person)<<"\n";
  cout<<CardStyle<<"\n";
}

void ReadPersons(stPerson Person[3])
{
  ReadInfo(Person[0]);
  ReadInfo(Person[1]);
  ReadInfo(Person[2]);
}

void DisplayCards(stPerson Person[3], string CardStyle)
{
  DisplayCard(Person[0], CardStyle);
  DisplayCard(Person[1], CardStyle);
  DisplayCard(Person[2], CardStyle);
}

int main()
{
  stPerson Person[2];

  ReadPersons(Person);
  DisplayCards(Person, "\n************************\n");
  return 0;
}
