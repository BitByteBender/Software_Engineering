#include <iostream>

using std::cout, std::endl;

short Add(int);

int main()
{
  short n{4};
  
  cout<<Add(n)<<"\n";
  
  return 0;
}

short Add(int n)
{
  if (n == 1)
  {
    return (1);
  }
  else
  {
    return (n + Add(n - 1));
  }
}
