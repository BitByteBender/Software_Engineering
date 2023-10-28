#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::string;

short Randomizer(short From, short To)
{
  short randNum = rand() % (To - From + 1) + From;
  return (randNum);
}

void Print3Numbers(short From, short To)
{
  uint16_t i;
  
  for (i = From; i <= 3; i++) {
     cout<<Randomizer(From, To)<<endl; 
  }
}

int main()
{
  srand((unsigned)time(NULL));
  
  Print3Numbers(1, 10);

  return 0;
}
