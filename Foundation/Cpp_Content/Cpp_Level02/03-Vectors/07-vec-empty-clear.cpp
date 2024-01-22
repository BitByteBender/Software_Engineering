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

  uint16_t num = vNumbers.at(2);
  cout<<"Number at index 2: "<<num<<'\n';

  num = vNumbers.at(5);
  cout<<"Number at index 5: "<<num<<'\n';

  num = vNumbers.at(4);
  cout<<"Number at index 4: "<<num<<'\n';

  num = vNumbers.at(7);
  cout<<"Number at index 7: "<<num<<'\n';

  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();
  vNumbers.pop_back();

  if (vNumbers.empty()) {
    cout<<"vector is empty"<<'\n';
  } else {
    cout<<"Numbers in vector: ";
    for (short &Nums : vNumbers) {
      cout<<Nums<<' ';
    }
    cout<<endl;
  }

  vNumbers.clear();

  if (vNumbers.empty()) {
    cout<<"vector is empty"<<endl;
  } else {
    cout<<"Numbers in vector: ";
    for (short &Nums : vNumbers) {
      cout<<Nums<<' ';
    }
    cout<<endl;
  }
  
  return (0);
}
