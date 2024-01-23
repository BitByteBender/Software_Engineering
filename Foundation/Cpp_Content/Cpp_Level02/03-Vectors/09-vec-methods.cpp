#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
  vector <uint16_t> vNums;
  vector <uint16_t> vNums2;
  
  vNums.push_back(15);
  vNums.push_back(99);
  vNums.push_back(115);
  vNums.push_back(999);
  vNums.push_back(333);

  for (const uint16_t &Nums : vNums) {
    cout<<Nums<<' ';
  }

  cout<<endl;

  vNums.front() = 51;
  vNums.back() = 69;

  vNums.at(3) = 9999;

  for (const uint16_t &Nums : vNums) {
    cout<<Nums<<' ';
  }
  cout<<endl;

  for (uint16_t &Nums : vNums) {
    if (Nums == 115) {
      Nums = 511;
    }
    cout<<Nums<<' ';
  }

  cout<<endl;

  uint16_t remainder = 0;
  for (uint16_t &Nums : vNums) {
    if (Nums != 9999) {
      if (Nums == 69) {
	remainder = (Nums % 10) * 10;
	Nums = remainder + uint16_t(Nums / 10);
	vNums2.push_back(Nums);
      }
      else
	vNums2.push_back(Nums);
    }
  }

  cout<<endl;

  for (const uint16_t &Nums : vNums2) {
    cout<<Nums<<' ';
  }

  cout<<endl;
  return (0);
}
