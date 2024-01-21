#include <iostream>
#include <ctime>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

inline uint16_t randomizer(uint16_t from, uint16_t to)
{
  return (rand() % (to - from + 1) + from);
}

int main(void)
{
  srand(unsigned(time(nullptr)));
  vector <uint16_t> vNums;

  vNums.push_back(randomizer(0, 100));
  vNums.push_back(randomizer(0, 100));
  vNums.push_back(randomizer(0, 100));
  vNums.push_back(randomizer(0, 100));
  vNums.push_back(randomizer(0, 100));
  
  //used by ref so it does not copy every single element
  for (uint16_t &nums : vNums) {
    cout<<nums<<' ';
  }

  cout<<endl;
  
  vNums.push_back(99);
  vNums.push_back(58);
  vNums.push_back(32);

  //used by ref so it does not copy every single element
  for (uint16_t &nums : vNums) {
    cout<<nums<<' ';
  }
  
  cout<<endl;
  
  return (0);
}
