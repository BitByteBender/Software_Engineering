#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ws;

enum enColors {
  Red = 0,
  Black = 1,
  White = 2,
  Gray = 3,
  Blue = 4,
  Yellow = 5,
};

struct stPersonData {
  string Fullname;
  uint16_t Age;
  enColors FavColor;
};

string dataReader(const char *Message)
{
  string Input{"Empty"};

  cout<<Message;
  getline(cin >> ws, Input);
  
  return (Input);
}

void ColorsDisplayer()
{
  cout<<"[Color's Menu]:"
      <<"\n[[0]> Red, [1]> Black, [2]> White]\n[[3]> Gray, [4]> Blue, [5]> Yellow]\n"
      <<endl;
}

stPersonData PersonRecord()
{
  stPersonData Person;
  uint16_t ColorPicker = 0;
  
  Person.Fullname = dataReader("What's your name?: ");
  Person.Age = stoi(dataReader("How old are you?: "));

  ColorsDisplayer();
  ColorPicker = stoi(dataReader("What's your favourite color?: "));
  Person.FavColor = (enColors) ColorPicker;
  
  return (Person);
}

string ColorPicker(enColors Color)
{
  string ColorPicker;
  
  switch (Color) {
  case (enColors::Red):
    ColorPicker = "Red";
    break;
  case (enColors::Black):
    ColorPicker = "Black";
    break;
  case (enColors::White):
    ColorPicker = "White";
    break;
  case (enColors::Gray):
    ColorPicker = "Gray";
    break;
  case (enColors::Blue):
    ColorPicker = "Blue";
    break;
  case (enColors::Yellow):
    ColorPicker = "Yellow";
    break;
  default:
    ColorPicker = "None";
  }

  return (ColorPicker);
}

int main(void)
{
  stPersonData Persons[3];
  uint16_t i = 0;
  
  for (i = 0; i < 3; ++i) {
    Persons[i] = PersonRecord();
  }
  
  for (const stPersonData &P : Persons) {
    cout<<"Fullname: "<<P.Fullname<<'\n'
	<<"Age: "<<P.Age<<'\n'
	<<"Favourite Color: "<<ColorPicker(P.FavColor)<<'\n'<<endl;
  }
  
  return (0);
}
