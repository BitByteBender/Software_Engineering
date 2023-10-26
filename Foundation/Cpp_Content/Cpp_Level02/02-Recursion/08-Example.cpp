#include <iostream>

using std::cout, std::endl;

short Factorial(short);

int main()
{
  short Num{5};

  cout<<Factorial(Num)<<"\n";
  return 0;
}

short Factorial(short Num)
{
  if (Num == 2) {
    return (Num);
  }
  else
  {
    return (Num * Factorial(Num - 1));
  }
}
