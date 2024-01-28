#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::fstream;
using std::vector;
using std::cout;
using std::endl;
using std::string;


void printDataBeforeUpdate(string Filename)
{
  fstream File;

  File.open(Filename, std::ios::in);

  if (File.is_open()) {
    string line;
    cout<<"File content before deletion:\n";
    
    while (getline(File, line)) {
      cout<<line<<'\n';
    }
    
    File.close();
  }
  
  cout<<"(EOF)"<<'\n'<<endl;
}

vector <string> dataLoader(string Filename)
{
  fstream File;
  vector <string> vLines;

  File.open(Filename, std::ios::in);

  if (File.is_open()) {
    string line;

    while (getline(File, line)) {
      vLines.push_back(line);
    }

    File.close();
  }

  return (vLines);
}

vector <string> deleteRecords(vector <string> &vLines, string record="PHP")
{
  vector <string>::iterator iter;
  
  for (iter = vLines.begin(); iter != vLines.end(); iter++) {
    if (*iter == record) {
      *iter = "PHP >> Laravel";
    };
  }

  return (vLines);
}

void saveRecordIntoFile(vector <string> vLines, string Filename)
{
  fstream File;

  File.open(Filename, std::ios::out);

  if (File.is_open()) {
    for (const string &Line : vLines) {
      if (Line != "") {
	File<<Line<<'\n';
      }
    }
    File.close();
  }
}

void printDataAfterUpdate(string Filename)
{
  fstream File;

  File.open(Filename, std::ios::in);

  if (File.is_open()) {
    string line;
    cout<<"File content before deletion:\n";
    
    while (getline(File, line)) {
      cout<<line<<'\n';
    }
    
    File.close();
  }
  cout<<"(EOF)"<<endl;
}

int main(void)
{
  string Filename = "tests/test06";
  vector <string> vLines;

  printDataBeforeUpdate(Filename);
  
  vLines = dataLoader(Filename);
  vLines = deleteRecords(vLines);

  saveRecordIntoFile(vLines, Filename);
  printDataAfterUpdate(Filename);
  return (0);
}
