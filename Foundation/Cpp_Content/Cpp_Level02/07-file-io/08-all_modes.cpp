#include <iostream>
#include <string.h>
#include <vector>

#define DELIM "#--#";

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ws;
using std::vector;
using std::to_string;

enum enColors {
  Red = 0,
  Black = 1,
  White = 2,
  Gray = 3,
  Blue = 4,
  Yellow = 5,
  Green = 6
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
      <<"\n[[0]> Red, [1]> Black, [2]> White], [3]> Gray]]\n"
      <<"[[4]> Blue, [5]> Yellow, [6]> Green, [7]> None]]\n"
      <<endl;
}

stPersonData PersonRecord()
{
  stPersonData Person;
  uint16_t ColorPicker = 0;
  
  Person.Fullname = dataReader("What's your name?: ");
  Person.Age = stoi(dataReader("How old are you?: "));

  ColorsDisplayer();

  do {
    ColorPicker = stoi(dataReader("What's your favourite color?: "));
  } while (ColorPicker > 7);
  
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

vector <stPersonData> PersonsRecords()
{
  vector <stPersonData> PrsRecs;
  char Decision = 'N';
  
  do {
    PrsRecs.push_back(PersonRecord());
    Decision = dataReader("Do you want to create another record? (Y/N): ")[0];
  } while (Decision == 'Y' || Decision == 'y');

  return (PrsRecs);
}

string lineRecs(stPersonData Person)
{
  string line;

  line = Person.Fullname + DELIM;
  line += to_string(Person.Age) + DELIM;
  line += ColorPicker(Person.FavColor);
  
  return (line);
}

vector <string> parseRecs(vector <stPersonData> PrsRecs)
{
  vector <string> LineRecs;
  
  for (const stPersonData &PR:PrsRecs) {
      LineRecs.push_back(lineRecs(PR));
  }
  
  return (LineRecs);
}

void DisplayRecordsFromVector(vector <stPersonData> &PrsRecs, vector <string> &LineRecs)
{
  for (const stPersonData &rec:PrsRecs) {
    cout<<"Fullname: "<<rec.Fullname<<'\n';
    cout<<"Age: "<<rec.Age<<'\n';
    cout<<"Fav-Color: "<<ColorPicker(rec.FavColor)<<'\n'<<endl;
  }
   
  for (string &lr:LineRecs) {
    cout<<lr<<endl;
  }
}

int main(void)
{
  vector <stPersonData> PrsRecs;
  vector <string> LineRecs;
  
  PrsRecs = PersonsRecords();
  LineRecs = parseRecs(PrsRecs);
  
  DisplayRecordsFromVector(PrsRecs, LineRecs);

  return (0);
}
