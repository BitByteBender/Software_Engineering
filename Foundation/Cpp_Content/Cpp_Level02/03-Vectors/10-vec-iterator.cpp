#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
  vector <short> vNums = {15, 78, 99, 60};

  vector <short>::iterator iter;

  for (iter = vNums.begin(); iter != vNums.end(); iter++) {
    cout<<*iter<<' ';
  }
  cout<<endl;
  
  return (0);
}
