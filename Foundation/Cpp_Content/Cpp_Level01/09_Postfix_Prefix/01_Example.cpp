#include <iostream>

using std::cout;
using std::endl;

int main()
{
  short X=25, Y{0};

  
  Y = X++; //Y will have the X value then X will increase by 1.
  cout<<"Y = "<<Y<<"\n";//Y = 25
  cout<<"X = "<<X<<"\n";//X = 26

  
  Y = ++X; //X will increase by 1, then Y will be 27
  cout<<"Y = "<<Y<<"\n";//Y = 27
  cout<<"X = "<<X<<endl;//X = 27
  return 0;
}
