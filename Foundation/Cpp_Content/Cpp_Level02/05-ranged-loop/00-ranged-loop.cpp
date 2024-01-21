#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
  int arr[] = {15, 9, 35, 55, 77};

  for (int numbers : arr) {
    cout<<numbers<<' ';
  }
  
  cout<<endl;
  
  return (0);
}
