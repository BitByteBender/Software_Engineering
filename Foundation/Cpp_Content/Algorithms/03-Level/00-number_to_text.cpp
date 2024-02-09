#include <iostream>
#include <string>

using std::cout;
using std::cin;

uint16_t readNumber(const char *Msg)
{
  uint16_t num{0};

  cout<<Msg;
  cin>>num;

  return (num);
}

int main(void)
{
  
  return (0);
}
