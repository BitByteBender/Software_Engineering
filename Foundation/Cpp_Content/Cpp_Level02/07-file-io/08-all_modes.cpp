#include <iostream>
#include <string.h>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ws;
using std::vector;

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

void DisplayRecordsFromVector(vector <stPersonData> &PrsRecs)
{
   for (const stPersonData &rec:PrsRecs) {
    cout<<"Fullname: "<<rec.Fullname<<'\n';
    cout<<"Age: "<<rec.Age<<'\n';
    cout<<"Fav-Color: "<<ColorPicker(rec.FavColor)<<'\n'<<endl;
  }
}

int main(void)
{
  vector <stPersonData> PrsRecs;
  PrsRecs = PersonsRecords();
  
  DisplayRecordsFromVector(PrsRecs);
  return (0);
}
