#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short Num1{5}, Num2{3}, Num3{47};
  short Array[3] = {0, 0, 0};
  short Array1[6] = {0, 0, 0, 0, 0, 0};
  
  
  cout<<"Array Address(Hexa-decimal) --> "<<Array<<"\n";
  cout<<"Array(Empty): \nat position 0: "<<Array[0]<<"\n"
      <<"at position 1: "<<Array[1]<<"\n"
      <<"at position 2: "<<Array[2]<<"\n\n";
  
  Array[0] = Num1;
  Array[1] = Num3;
  Array[2] = Num2;
  cout<<"Array(Filled): \nat position 0: "<<Array[0]<<"\n"
      <<"at position 1: "<<Array[1]<<"\n"
      <<"at position 2: "<<Array[2]<<"\n\n";

  Array1[0] = 01;
  Array1[1] = 99;
  Array1[2] = Num2;
  Array1[3] = Array[1];
  Array1[4] = 78;
  Array1[5] = Array[0];
  cout<<"Array1 Address(Hexa-decimal) --> "<<Array1<<"\n";
  cout<<"Array(Filled): \nat position 0: "<<Array1[0]<<"\n"
      <<"at position 1: "<<Array1[1]<<"\n"
      <<"at position 2: "<<Array1[2]<<"\n"
      <<"at position 3: "<<Array1[3]<<"\n"
      <<"at position 4: "<<Array1[4]<<"\n"
      <<"at position 5: "<<Array1[5]<<"\n\n";

  short Array2[8] = {777, Num1, Num2, Array[1], 555, Num3, 666, Array1[5]};

  cout<<"Array2 Address(Hexa-decimal) --> "<<Array2<<"\n";
  cout<<"Array(Filled): \nat position 0: "<<Array2[0]<<"\n"
      <<"at position 1: "<<Array2[1]<<"\n"
      <<"at position 2: "<<Array2[2]<<"\n"
      <<"at position 3: "<<Array2[3]<<"\n"
      <<"at position 4: "<<Array2[4]<<"\n"
      <<"at position 5: "<<Array2[5]<<"\n"
      <<"at position 6: "<<Array2[6]<<"\n"
      <<"at position 7: "<<Array2[7]<<"\n";
  return 0;
}
