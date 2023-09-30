#include <iostream>
#include "cmath"

using std::cout;
using std::endl;


int main()
{
  int A{15}, B{78}, C{21}, D{19}, E{26}, F{34};

  int FirstArr[3] = {42, 23, 567};
  int SecondArr[5] = {FirstArr[2], C, 56, 782, F};
  int ThirdArr[4] = {D, SecondArr[4], FirstArr[1], (SecondArr[3] * 3)};

  cout<<"At position 0: "<<FirstArr[0] + SecondArr[0] + ThirdArr[0]<<"\n";
  cout<<"At position 1: "<<FirstArr[1] + SecondArr[1] + ThirdArr[1]<<"\n";
  cout<<"At position 2: "<<FirstArr[2] + 50 + ThirdArr[2] + SecondArr[2]<<"\n";
  cout<<"At position 3: "<<floor(floor(pow(A, 8) / 100) / (ThirdArr[3] * SecondArr[3]))<<"\n";
  cout<<"At position 4: "<<SecondArr[4] * 5 + sqrt(pow(2, 6))<<endl;
  return 0;
}
