#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
  vector <uint16_t> vNums = {5, 7, 9, 3};

  for (uint16_t nums : vNums) {
    cout<<nums<<' ';
  }
  
  cout<<endl;
  
  return (0);
}
