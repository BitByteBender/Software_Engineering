#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short Age{39};
  short* ptr = &Age;

  cout<<"The value of Age: "<<Age<<"\n";//39
  cout<<"The address of Age: "<<&Age<<"\n\n";

  cout<<"The value of an integer pointer to age: "<<*ptr<<"\n";//39
  cout<<"The address of ptrAge: "<<ptr<<"\n\n";

  //dereferencing
  *ptr = 45;

  cout<<"The value of Age: "<<Age<<"\n";//45
  cout<<"The address of Age: "<<&Age<<"\n\n";

  cout<<"The value of an integer pointer to age: "<<*ptr<<"\n";//45
  cout<<"The address of ptrAge: "<<ptr<<"\n\n";

  short Number1{111};
  //pointing
  ptr = &Number1;

  cout<<"The value of Age: "<<Age<<"\n";//45
  cout<<"The address of Age: "<<&Age<<"\n\n";

  cout<<"The value of Number1: "<<Number1<<"\n";//111
  cout<<"The address of Number1: "<<&Number1<<"\n\n";
  
  cout<<"The value of an integer pointer to age: "<<*ptr<<"\n";//111
  cout<<"The address of ptrAge: "<<ptr<<"\n\n";

  //dereferencing
  *ptr = 222;

  //pointing
  ptr = &Age;

  cout<<"The value of Age: "<<Age<<"\n";//45
  cout<<"The address of Age: "<<&Age<<"\n\n";

  cout<<"The value of Number1: "<<Number1<<"\n";//222
  cout<<"The address of Number1: "<<&Number1<<"\n\n";
  
  cout<<"The value of an integer pointer to age: "<<*ptr<<"\n";//45
  cout<<"The address of ptrAge: "<<ptr<<"\n\n";
  return 0;
}
