#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

enum enColors{Red = 'R', Black = 'B', Tortoise = 'T'};

struct stContactDetails
{
  string Street1{"empty"};
  string Phone{"empty"};
};

struct stLocation
{
  string City{"empty"}, Country{"empty"};
  stContactDetails Contact;
};

struct stPersonData
{
  string Fullname{"empty"};
  unsigned short Age{0};
  stLocation Loc;
  enColors FavColor;
};

short ReadPostiveNumber(string Message)
{
  short Num{0};

  do {
    cout<<Message;
    cin>>Num;
  } while (Num < 0);
  
  return (Num);
}

void ReadPersonData(stPersonData &Person)
{
  cout<<"Enter the fullname: ";
  getline(cin, Person.Fullname);
  
  Person.Age = ReadPostiveNumber("Enter your age: ");

  cout<<"Enter your city: ";
  cin>>Person.Loc.City;

  cout<<"Enter your country: ";
  cin>>Person.Loc.Country;

  cout<<"Enter your street: ";
  cin.ignore(1, '\n');
  getline(cin, Person.Loc.Contact.Street1);

  cout<<"Enter your phone: ";
  cin>>Person.Loc.Contact.Phone;
  
  char ColorPicker{'x'};

  cout<<"Choose a color: ";
  cin>>ColorPicker;
  
  Person.FavColor = (enColors) ColorPicker;
}

string PickColor(stPersonData Person)
{
  switch (Person.FavColor)
  {
  case enColors::Red:
    return "Red";
  case enColors::Black:
    return "Black";
  case enColors::Tortoise:
    return "Tortoise";
  default:
    return "Not a color in our palette.";
  }
}

void PrintPersonData(stPersonData Person, string CardStyle)
{
  cout<<CardStyle;
  cout<<"Fullname: "<<Person.Fullname<<"\n";
  cout<<"Age: "<<Person.Age<<"\n";
  cout<<"City: "<<Person.Loc.City<<"\n";
  cout<<"Country: "<<Person.Loc.Country<<"\n";
  cout<<"Street1: "<<Person.Loc.Contact.Street1<<"\n";
  cout<<"Phone: "<<Person.Loc.Contact.Phone<<"\n";
  cout<<"Fav-Color: "<<PickColor(Person)<<"\n";
  cout<<CardStyle<<endl;
}

void ReadPersonsData(stPersonData Person[5], unsigned short Index)
{
  unsigned short i;
  for (i = 0; i <= (Index - 1); i++) {
    cout<<"Enter Person "<<i+1<<" Data:\n";
    ReadPersonData(Person[i]);
    cin.ignore(1, '\n');
  }
}

void PrintPersonsData(stPersonData Person[3], unsigned short Index, string CardStyle)
{
  unsigned short i;
  for (i = 0; i <= (Index - 1); i++) {
    cout<<"Enter Person "<<i+1<<" Data:\n";
    PrintPersonData(Person[i], CardStyle);
  }
}

int main()
{
  stPersonData Person[3];
  unsigned short Index{3};
  string CardStyle = "----------------//--\\\\----------------\n";
  
  ReadPersonsData(Person, Index);
  PrintPersonsData(Person, Index, CardStyle);
  return 0;
}
