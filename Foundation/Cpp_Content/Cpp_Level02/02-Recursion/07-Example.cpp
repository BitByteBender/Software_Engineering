#include <iostream>

using std::cout, std::endl;

short Factorial(short);

int main()
{
  short Num{7};

  cout<<Factorial(Num)<<"\n";
  return 0;
}

short Factorial(short Num)
{
  if (Num == 1) {
    return (1);
  }
  else
  {
    return (Num * Factorial(Num - 1));
  }
}
