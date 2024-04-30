#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

#define DELIM "#--#";

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ws;
using std::vector;
using std::to_string;
using std::fstream;
using std::ios;

enum enColors {
  Red = 0,
  Black = 1,
  White = 2,
  Gray = 3,
  Blue = 4,
  Yellow = 5,
  Green = 6,
  None = 7
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
  case (enColors::Green):
    ColorPicker = "Green";
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

void overrideRecords(vector <string> LineRecs, string PATH="tests/test07")
{
  fstream FILE;
  
  FILE.open(PATH, ios::out);
  
  if (FILE.is_open()) {
    for (const string &Recs:LineRecs) {
      FILE<<Recs<<'\n';
    }
    FILE.close();
  }
}

vector <string> loadLineRecords(string PATH="tests/test07")
{
  fstream FILE;
  string line;
  vector <string> vRecs;
  
  FILE.open(PATH, ios::in);

  if (FILE.is_open()) {
    while (getline(FILE, line)) {
      if (!line.empty()) {
	vRecs.push_back(line);
	cout<<line<<'\n';
      }
    }
    FILE.close();
  }

  return (vRecs);
}

vector <string> splitString(string line, string DELIMITER)
{
  vector <string> vPerson;
  short pos = 0;

  while ((pos = line.find(DELIMITER)) != string::npos) {
    vPerson.push_back(line.substr(0, pos));
    line.erase(0, pos + DELIMITER.length());
  }

  if (!line.empty()) {
    vPerson.push_back(line);
    line.clear();
  }

  return (vPerson);
}

enColors ColorRebase(string strColor)
{
  enColors OriginalColor;
  
  if (strColor == "Red") {
    OriginalColor = enColors::Red;
  } else if (strColor == "Black") {
    OriginalColor = enColors::Black;
  } else if (strColor == "White") {
    OriginalColor = enColors::White;
  } else if (strColor == "Gray") {
    OriginalColor = enColors::Gray;
  } else if (strColor == "Blue") {
    OriginalColor = enColors::Blue;
  } else if (strColor == "Yellow") {
    OriginalColor = enColors::Yellow;
  } else if (strColor == "Green") {
    OriginalColor = enColors::Green;
  } else {
    OriginalColor = enColors::None;
  }

  return (OriginalColor);
}

stPersonData DataFiller(vector <string> vPerson)
{
  stPersonData Person;

  Person.Fullname = vPerson[0];
  Person.Age = stoi(vPerson[1]);
  Person.FavColor = ColorRebase(vPerson[2]);

  return (Person);
}

vector <stPersonData> PersonsDataRecs(vector <string> &vPerson, stPersonData &Person)
{
  vector <stPersonData> vecPerson;

  for (const string &prs:vPerson) {
    Person = DataFiller(splitString(prs, "#--#"));
    vecPerson.push_back(Person);
  }

  return (vecPerson);
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
  stPersonData Person;
  vector <stPersonData> PrsRecs;
  vector <string> LineRecs;
  vector <stPersonData> vPersons;
  
  PrsRecs = PersonsRecords();
  LineRecs = parseRecs(PrsRecs);

  overrideRecords(LineRecs);
  LineRecs = loadLineRecords();

  vPersons = PersonsDataRecs(LineRecs, Person);
  
  for (const stPersonData &prs:vPersons) {
    cout<<"Fullname: "<<prs.Fullname<<'\n';
    cout<<"Age: "<<prs.Age<<'\n';
    cout<<"Color: "<<ColorPicker(prs.FavColor)<<" <[Code: "<<prs.FavColor<<']'<<"\n\n";
  }
  
  return (0);
}
