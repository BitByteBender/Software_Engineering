#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

enum enCollection
{
  SmallLetter = 0,
  CapitalLetter = 1,
  SpecialChars = 2,
  Digit = 3
};

short Randomizer(short From, short To)
{
  short RandNum = rand() % (To - From + 1) + From;
  return (RandNum);
}

char PickRandom(enCollection Collect)
{
  switch (Collect)
  {
  case enCollection::SmallLetter:
    return char(Randomizer(97, 122));
  case enCollection::CapitalLetter:
    return char(Randomizer(65, 90));
  case enCollection::SpecialChars:
    return (char(Randomizer(32, 64)));
  case enCollection::Digit:
    return char(Randomizer(48, 57));

  default:
    return '0';
  }
}

void PrintPickedCollection(enCollection Collect)
{
  cout<<PickRandom(Collect)<<endl;
}

int main()
{
  srand((unsigned)time(NULL));
  
  PrintPickedCollection(enCollection::SmallLetter);
  PrintPickedCollection(enCollection::CapitalLetter);
  PrintPickedCollection(enCollection::SpecialChars);
  PrintPickedCollection(enCollection::Digit);
  return 0;
}
