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


int main(void)
{
  string testArr[5];
  uint16_t i = 0, counter = 0;

  for (i = 0; i < 5; ++i) {
    cout<<'['<<i<<']';
    testArr[i] = dataReader("enter a test: ");
  }

  while (i != 0) {
    cout<<'['<<counter<<"]: "<<testArr[counter]<<endl;
    counter++;
    i--;
  }
  
  return (0);
}
