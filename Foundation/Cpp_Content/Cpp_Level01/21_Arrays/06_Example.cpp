#include <iostream>
#include "cmath"

using std::cout;
using std::endl;
using std::cin;

int main()
{
  short Arr1[2] = {45, 15};
  short Arr2[4] = {Arr1[0], 78, 999, 52};
  short Arr3[3] = {((12 * 15)/2), 78, short(pow(Arr2[0], 2))};

  cout<<"Array1 at position 0: "<<Arr1[0]<<"\n";
  cout<<"Array1 at position 1: "<<Arr1[1]<<"\n\n";

  cout<<"Array2 at position 0: "<<Arr2[0]<<"\n";
  cout<<"Array2 at position 1: "<<Arr2[1]<<"\n";
  cout<<"Array2 at position 2: "<<Arr2[2]<<"\n";
  cout<<"Array2 at position 3: "<<Arr2[3]<<"\n\n";

  cout<<"Array3 at position 0: "<<Arr3[0]<<"\n";
  cout<<"Array3 at position 1: "<<Arr3[1]<<"\n";
  cout<<"Array3 at position 2: "<<Arr3[2]<<endl;
  return 0;
}
