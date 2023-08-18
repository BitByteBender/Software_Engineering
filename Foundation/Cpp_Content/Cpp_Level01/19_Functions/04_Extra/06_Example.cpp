#include <iostream>

using std::cout;
using std::endl;

short CalculateRectangleArea(short Base, short Height){
  return Base * Height;
}

void PrintRectangleArea(short Base, short Height){
  
  cout<<"The Triangle Area is: "<<CalculateRectangleArea(Base, Height)<<endl;

}

int main()
{
  short Base{42}, Height{12};
  PrintRectangleArea(Base, Height);
  return 0;
}
