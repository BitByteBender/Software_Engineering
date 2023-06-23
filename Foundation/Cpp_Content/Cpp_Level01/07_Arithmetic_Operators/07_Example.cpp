#include <iostream>

using std::cout;
using std::endl;

int main()
{
  //Rectangle area = Width x Length
  unsigned short Width{10}, Length{20};
  
  unsigned short RectangleArea = Width * Length;
  cout<<"Rectangle Area: "<<RectangleArea<<endl;
  return 0;
}
