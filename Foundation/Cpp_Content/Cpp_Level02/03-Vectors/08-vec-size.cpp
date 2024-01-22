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
  vNumbers.push_back(115);
  vNumbers.push_back(85);
  vNumbers.push_back(49);
  vNumbers.push_back(999);

  cout<<"Numbers in vector: ";
  for (short &Nums : vNumbers) {
    cout<<Nums<<' ';
  }

  cout<<endl;

  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();

  cout<<"vector's size: "<<vNumbers.size()<<'\n';

  vNumbers.clear();

  cout<<"vector's size: "<<vNumbers.size()<<endl;
  
  return (0);
}
