#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
  vector <short> vNumbers;

  vNumbers.push_back(78);
  vNumbers.push_back(35);
  vNumbers.push_back(14);
  vNumbers.push_back(64);
  vNumbers.push_back(99);

  cout<<"Numbers in vector: ";
  for (short &Nums : vNumbers) {
    cout<<Nums<<' ';
  }

  cout<<endl;
  
  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();

  cout<<"Numbers left in vector: ";
  for (short &poppedNums : vNumbers) {
    cout<<poppedNums<<' ';
  }

  cout<<endl;

  uint16_t number = vNumbers.at(0);
  cout<<number<<endl;
  
  return (0);
}
