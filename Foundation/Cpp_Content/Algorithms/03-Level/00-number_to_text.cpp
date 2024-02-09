#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::to_string;

uint16_t readNumber(const char *Msg)
{
  uint16_t num{0};

  cout<<Msg;
  cin>>num;

  return (num);
}

uint16_t digitCount(uint16_t num)
{
  return (to_string(num).length()); 
}

string convertNumToText(uint16_t num)
{
  uint16_t digits = digitCount(num);
  string Text;

  //Logic WIP
  return (Text);
}

int main(void)
{
  uint16_t num = readNumber("Enter a number: ");
  convertNumToText(num);
  return (0);
}
