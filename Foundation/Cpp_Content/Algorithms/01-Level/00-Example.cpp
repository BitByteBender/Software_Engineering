#include <iostream>

using std::cout;
using std::endl;

void Display_Header(short &Min, short &Max)
{
  cout<<"\t\t\tMultiplication Table From "<<Min<<" to "<<Max<<"\n\n";

  unsigned short i;

  for (i = Min; i <= Max; i++) {
    cout<<'\t'<<i;
  }

  cout<<"\n";
  
  for (i = Min; i < Max; i++) {
    cout<<"_________";
  }
  
  cout<<'_'<<endl;
    
}

short Mul_Table(short Min, short Max)
{
  return (Min * Max);
}

std::string ColumnSeparator(short Min, short Max)
{
  if (Min < Max) {
    return "    | ";
  }
  else
  {
    return "   | ";
  }
}

void PrintMulti_Table()
{
  short Min{1}, Max{10};
  unsigned short i, j;

  Display_Header(Min, Max);
  
  for (i = Min; i <= Max; i++) {
    cout<<' '<<i<<ColumnSeparator(i, Max);


    for (j = Min; j <= Max; j++) {
    cout<<Mul_Table(i, j)<<'\t';
    }

    cout<<'\n';
  }
  
  cout<<endl;
}

int main()
{
  PrintMulti_Table();
  return 0;
}
