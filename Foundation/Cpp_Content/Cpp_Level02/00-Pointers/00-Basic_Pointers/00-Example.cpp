#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short Age{39};

  short* ptrAge = &Age;

  cout<<"The value of Age: "<<Age<<"\n";
  cout<<"The address of Age: "<<&Age<<"\n\n";

  cout<<"The value of an integer pointer to age: "<<*ptrAge<<"\n";
  cout<<"The address of ptrAge: "<<ptrAge<<"\n\n";
  return 0;
}
