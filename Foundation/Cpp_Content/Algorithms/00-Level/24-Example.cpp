#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void ReadNumbers(short &Height, short &Width)
{
  cout<<"Enter height: ";
  cin>>Height;

  cout<<"Enter width: ";
  cin>>Width;
}

short CalculateArea(short Height, short Width)
{
  return (Height * Width);
}

void PrintArea(short Height, short Width)
{
  cout<<"Rectangle Area: "<<CalculateArea(Height, Width)<<endl;
}

int main()
{
  short Height{0}, Width{0};

  ReadNumbers(Height, Width);
  PrintArea(Height, Width);
  return 0;
}
