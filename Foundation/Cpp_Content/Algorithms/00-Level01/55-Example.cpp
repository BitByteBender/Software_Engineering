#include <iostream>

using std::cout;
using std::endl;

void PrintAlphabets()
{
  unsigned short i;

  for (i = 65; i <= 90; i++)
  {
    cout<<(char)i<<"\n";
  }
  
  cout<<endl;
    
}

int main()
{
  PrintAlphabets();
  return 0;
}

