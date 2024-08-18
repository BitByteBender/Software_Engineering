#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct stDate
{
  uint16_t Year;
  uint16_t Month;
  uint16_t Day;
};

uint16_t DataPrompt(const char *Message)
{
  uint16_t Num{0};

  cout<<Message;
  cin>>Num;
  
  return (0);
}

int main(void)
{
  
  return (0);
}
