#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
  vector <uint16_t> vNums = {10, 5, 16, 87, 36};

  //used by ref so it does not copy every single element
  for (uint16_t &nums : vNums) {
    cout<<nums<<'\n';
  }
  
  return (0);
}

