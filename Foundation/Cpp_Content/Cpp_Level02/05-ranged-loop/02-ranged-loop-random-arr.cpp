#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void readNum(const char *Msg, uint16_t &length)
{
  cout<<Msg;
  cin>>length;
}

inline uint16_t randomizer(uint16_t from, uint16_t to)
{
  return (rand() % (to - from + 1) + from);
}

void fillArr(uint16_t array[], uint16_t length)
{
  uint16_t i = 0;
  
  for (i = 0; i <= (length - 1); i++) {
    array[i] = randomizer(0, 9);
  }
}

int main(void)
{
  srand(uint16_t(time(nullptr)));
  
  uint16_t length{0};
  
  readNum("Enter a length: ", length);

  uint16_t arr[length];

  fillArr(arr, length);

  for (uint16_t nums : arr) {
    cout<<nums<<' ';
  }
  
  cout<<endl;
  
  return (0);
}
